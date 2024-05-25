# Lexical-Analyzer
Lexical analyzers are designed to recognize keywords, operators and identifiers. It can also include others like integers, floating point numbers, character strings and other similar items that are written as part of the source program. Typically, they are given names a tokens, which are parsed in the given input and match against a pre-defined rules called grammar. When the given program is not matching with this grammar, the error is provided to the user in form of compilation error. 

A token is a string of characters, categorized according to the rules as a symbol (e.g. Identifier, Number, Comma etc…). The process of forming tokens from an input stream of characters is called tokenization, and the lexer categorizes them according to a symbol type. A token can look like anything that is useful for processing an input text stream or text file. A lexical analyzer generally does nothing with combinations of tokens, a task left for a parser. For example, a typical lexical analyzer recognizes parentheses as tokens, but does nothing to ensure that each “(” is matched with a “)”, which happens in subsequent steps. 

## Requirement Details
Given the input C program, your lexical analyzer should do the following:

- It should identify all the keywords
- It should identify all the Identifiers.
- It should identify the literals, such as float , characters, string literals, decimals.
- It should identify the arrays.

## Screenshots


Fig1: Usage
![la_1-1](https://github.com/sufiyanattar/Lexical-Analyzer/assets/109298044/51da6934-c183-4952-a007-6aaa4bae2e13)


Fig2: Sample C File to be Parsed

![la_2](https://github.com/sufiyanattar/Lexical-Analyzer/assets/109298044/ba0fe8f4-35a3-40df-ae95-43d13e62ab17)


Fig3: Expected Output
![la_3](https://github.com/sufiyanattar/Lexical-Analyzer/assets/109298044/7810c0d2-6601-4ad8-9372-cc10adf26b39)

