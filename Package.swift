// swift-tools-version:5.9

import PackageDescription

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
  targets: [
    .binaryTarget(
      name: "BanubaVideoEditorSDK",
      path: "BanubaVideoEditorSDK.xcframework"
    )
  ]
)
