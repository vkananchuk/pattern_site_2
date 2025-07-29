import XCTest
import SwiftTreeSitter
import TreeSitterBugfixTranslation

final class TreeSitterBugfixTranslationTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_bugfix_translation())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Bugfix Translation grammar")
    }
}
