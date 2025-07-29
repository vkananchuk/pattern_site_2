// swift-tools-version:5.3

import Foundation
import PackageDescription

var sources = ["src/parser.c"]
if FileManager.default.fileExists(atPath: "src/scanner.c") {
    sources.append("src/scanner.c")
}

let package = Package(
    name: "TreeSitterBugfixTranslation",
    products: [
        .library(name: "TreeSitterBugfixTranslation", targets: ["TreeSitterBugfixTranslation"]),
    ],
    dependencies: [
        .package(name: "SwiftTreeSitter", url: "https://github.com/tree-sitter/swift-tree-sitter", from: "0.9.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterBugfixTranslation",
            dependencies: [],
            path: ".",
            sources: sources,
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterBugfixTranslationTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterBugfixTranslation",
            ],
            path: "bindings/swift/TreeSitterBugfixTranslationTests"
        )
    ],
    cLanguageStandard: .c11
)
