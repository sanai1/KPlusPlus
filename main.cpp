#pragma once

#include <iostream>
#include "lexer/LexerImplementation.hpp"

using namespace std;

int main() {
    LexerImplementation lexer = LexerImplementation();
    vector<TokenImplementation> tokens = lexer.tokenize("int x = number; double y = 10;");

    for (auto & token : tokens) {
        cout << "TokenType -> " << static_cast<int>(token.getToken()) << endl;
        cout << "value -> " << token.getValue() << endl;
        cout << "numberString -> " << token.getNumberString() << endl;
        cout << endl;
    }

    return 0;
}