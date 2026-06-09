// swift-tools-version:5.9

import PackageDescription

let designSystemVersionRange: Range<Version> = "1.0.0-beta.0"..<"2.0.0"
let banubaUtilsVersionRange: Range<Version> = "1.53.0-beta.0"..<"1.53.99"
let banubaCoreVersionRange: Range<Version> = "1.53.0-beta.0"..<"1.53.99"
let banubaLicenseServicingVersionRange: Range<Version> = "1.53.0-beta.0"..<"1.53.99"

let package = Package(
  name: "BanubaVideoEditorSDK",
  platforms: [
    .iOS(.v15)
  ],
  products: [
    .library(
      name: "BanubaVideoEditorSDK",
      targets: ["BanubaVideoEditorSDKTarget"]
    )
  ],
  dependencies: [
    .package(url: "https://github.com/Banuba/BanubaDesignSystem.git", designSystemVersionRange),
    .package(url: "https://github.com/Banuba/BanubaUtilities-iOS.git", banubaUtilsVersionRange),
    .package(url: "https://github.com/Banuba/BanubaVideoEditorCore-iOS.git", banubaCoreVersionRange),
    .package(url: "https://github.com/Banuba/BanubaLicenseServicingSDK.git", banubaLicenseServicingVersionRange),
  ],
  targets: [
    .target(
      name: "BanubaVideoEditorSDKWrapper",
      dependencies: [
        "BanubaVideoEditorSDK",
        .product(name: "BanubaDesignSystem", package: "BanubaDesignSystem"),
        .product(name: "BanubaUtilities", package: "BanubaUtilities-iOS"),
        .product(name: "BanubaVideoEditorCore", package: "BanubaVideoEditorCore-iOS"),
        .product(name: "BanubaLicenseServicingSDK", package: "BanubaLicenseServicingSDK")
      ],
      path: "BanubaVideoEditorSDKWrapper"
    ),
    .target(
      name: "BanubaVideoEditorSDKTarget",
      dependencies: [
        .target(name: "BanubaVideoEditorSDKWrapper")
      ],
      path: "BanubaVideoEditorSDKTarget"
    ),
    // Local development uses the path-based binaryTarget below.
    // Release flow (fastlane patch_package_swift_for_nexus) replaces it in the GitHub distribution repo with:
    // .binaryTarget(
    //   name: "BanubaVideoEditorSDK",
    //   url: "https://nexus.banuba.net/repository/ios-frameworks/ios/frameworks/BanubaVideoEditorSDK/{version}/BanubaVideoEditorSDK-{version}.xcframework.zip",
    //   checksum: "{computed at release}"
    // )
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      url: "https://nexus.banuba.net/repository/ios-frameworks/ios/frameworks/BanubaVideoEditorSDK/1.53.0-beta.2/BanubaVideoEditorSDK-1.53.0-beta.2.xcframework.zip",
      checksum: "d08d265e702ad0ac85224e98c90d956d8e1c8054d31696806bbbc9f7424f3386"
    )
  ]
)
