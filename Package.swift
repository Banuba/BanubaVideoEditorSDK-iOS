// swift-tools-version:5.9

import PackageDescription

let utilsVersionRange: Range<Version> = "1.40.0-beta.3"..<"1.49.99"

let package = Package(
  name: "BanubaVideoEditorSDK",
  platforms: [
    .iOS(.v15)
  ],
  products: [
    .library(
      name: "BanubaVideoEditorSDK",
      targets: ["BanubaVideoEditorSDK"]
    )
  ],
  dependencies: [
    .package(url: "https://github.com/Banuba/BanubaUtilities-iOS.git", utilsVersionRange),
    .package(url: "https://github.com/Banuba/BanubaVideoEditorCore-iOS.git", utilsVersionRange),
    .package(url: "https://github.com/Banuba/BanubaLicenseServicingSDK.git", utilsVersionRange),
  ],
  targets: [
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      path: "BanubaVideoEditorSDK.xcframework"
    )
  ]
)
