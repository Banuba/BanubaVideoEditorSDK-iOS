// swift-tools-version:5.3
import PackageDescription
let package = Package(
  name: "BanubaVideoEditorSDK",
  platforms: [
    .iOS(.v11)
  ],
  products: [
    .library(
      name: "BanubaVideoEditorSDK",
      targets: ["BanubaVideoEditorSDK"])
  ],
  targets: [
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      path: "BanubaVideoEditorSDK.xcframework")
  ])
