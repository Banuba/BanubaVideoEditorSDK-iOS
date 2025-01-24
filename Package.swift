// swift-tools-version:5.9

import PackageDescription

let utilsVersionRange: Range<Version> = "1.40.0"..<"1.49.99"

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
    .package(url: "https://github.com/Banuba/BanubaUtilities-iOS.git", utilsVersionRange),
    .package(url: "https://github.com/Banuba/BanubaVideoEditorCore-iOS.git", utilsVersionRange),
    .package(url: "https://github.com/Banuba/BanubaLicenseServicingSDK.git", utilsVersionRange),
  ],
  targets: [
    .target(
      name: "BanubaVideoEditorSDKWrapper",
      dependencies: [
        "BanubaVideoEditorSDK",
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
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      path: "BanubaVideoEditorSDK.xcframework"
    )
  ]
)
