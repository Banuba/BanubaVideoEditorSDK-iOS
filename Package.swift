// swift-tools-version:5.3
import PackageDescription
let package = Package(
  name: "BanubaLicenseServicingSDK",
  platforms: [
    .iOS(.v11)
  ],
  products: [
    .library(
      name: "BanubaLicenseServicingSDK",
      targets: ["BanubaLicenseServicingSDK"])
  ],
  targets: [
    .binaryTarget(
      name: "BanubaLicenseServicingSDK",
      path: "BanubaLicenseServicingSDK.xcframework")
  ])
