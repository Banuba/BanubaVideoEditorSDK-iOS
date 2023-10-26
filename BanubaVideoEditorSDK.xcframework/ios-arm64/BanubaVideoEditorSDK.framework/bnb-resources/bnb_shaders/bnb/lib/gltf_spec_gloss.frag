#include <bnb/glsl.frag>

precision mediump float;
precision mediump sampler2DArray;
precision mediump sampler2DShadow;

BNB_IN(0)
vec2 var_uv;
BNB_IN(1)
vec3 var_t;
BNB_IN(2)
vec3 var_b;
BNB_IN(3)
vec3 var_n;
BNB_IN(4)
vec3 var_v;

BNB_DECLARE_SAMPLER_2D(0, 1, diffuse);
BNB_DECLARE_SAMPLER_2D(2, 3, spec_gloss);
BNB_DECLARE_SAMPLER_2D(4, 5, normal);
BNB_DECLARE_SAMPLER_CUBE(6, 7, tex_ibl_diff);
BNB_DECLARE_SAMPLER_CUBE(8, 9, tex_ibl_spec);
BNB_DECLARE_SAMPLER_2D(12, 13, emissive);

// gamma to linear
vec3 g2l(vec3 g)
{
    return g * (g * (g * 0.305306011 + 0.682171111) + 0.012522878);
}

// combined hdr to ldr and linear to gamma
vec3 l2g(vec3 l)
{
    return sqrt(1.33 * (1. - exp(-l))) - 0.03;
}

vec3 fresnel_schlick_roughness(float prod, vec3 F0, float roughness)
{
    return F0 + (max(F0, 1. - roughness) - F0) * pow(1. - prod, 5.);
}

vec2 brdf_approx(float Roughness, float NoV)
{
    const vec4 c0 = vec4(-1., -0.0275, -0.572, 0.022);
    const vec4 c1 = vec4(1., 0.0425, 1.04, -0.04);
    vec4 r = Roughness * c0 + c1;
    float a004 = min(r.x * r.x, exp2(-9.28 * NoV)) * r.x + r.y;
    vec2 AB = vec2(-1.04, 1.04) * a004 + r.zw;
    return AB;
}

void main()
{
    vec4 diffuse_opacity = texture(BNB_SAMPLER_2D(diffuse), var_uv);

    vec3 diffuse_color = g2l(diffuse_opacity.xyz);
    float opacity = diffuse_opacity.w;

    vec4 specular_glossiness = texture(BNB_SAMPLER_2D(spec_gloss), var_uv);
    vec3 F0 = g2l(specular_glossiness.xyz);

    float roughness = 1. - specular_glossiness.w;

    vec3 N = normalize(mat3(var_t, var_b, var_n) * (texture(BNB_SAMPLER_2D(normal), var_uv).xyz * 2. - 1.));
    N *= gl_FrontFacing ? 1. : -1.;

    vec3 V = normalize(-var_v);
    float cN_V = max(0., dot(N, V));
    vec3 R = reflect(-V, N);

    vec3 F = fresnel_schlick_roughness(cN_V, F0, roughness);
    vec3 kD = 1. - F;

    vec3 diffuse_lighting = texture(BNB_SAMPLER_CUBE(tex_ibl_diff), N).xyz * diffuse_color;

    const float MAX_REFLECTION_LOD = 7.; // number of mip levels in tex_ibl_spec
    vec3 prefilteredColor = textureLod(BNB_SAMPLER_CUBE(tex_ibl_spec), R, roughness * MAX_REFLECTION_LOD).xyz;
    vec2 brdf = brdf_approx(roughness, cN_V);
    vec3 specular = prefilteredColor * (F0 * brdf.x + brdf.y);

    vec3 color = (kD * diffuse_lighting + specular);

    color += g2l(texture(BNB_SAMPLER_2D(emissive), var_uv).xyz);

    bnb_FragColor = vec4(l2g(color), opacity);
}
