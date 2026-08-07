// swift-tools-version:5.9

import PackageDescription

let designSystemVersionRange: Range<Version> = "1.0.4"..<"2.0.0"
let banubaUtilsVersionRange: Range<Version> = "1.53.2"..<"1.53.99"
let banubaCoreVersionRange: Range<Version> = "1.53.1"..<"1.53.99"
let banubaLicenseServicingVersionRange: Range<Version> = "1.53.2"..<"1.53.99"

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
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      url: "https://nexus.banuba.net/repository/ios-frameworks/ios/frameworks/BanubaVideoEditorSDK/1.53.2/BanubaVideoEditorSDK-1.53.2.xcframework.zip",
      checksum: "7b71736449f815497e624d9b877c2fef85cc34d6733bdca43770d00d754d0b91"
    )
  ]
)
