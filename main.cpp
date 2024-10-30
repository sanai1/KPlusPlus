#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer/LexerImplementation.hpp"

using namespace std;

const string fileProgramText = "testProgram.kpp";

string readProgram() {
    ifstream file(fileProgramText);
    stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

int main() {
    LexerImplementation lexer = LexerImplementation();
    string textProgram = readProgram();
    vector<TokenImplementation> tokens = lexer.tokenize(textProgram);

    for (auto & token : tokens) {
        cout << "TokenType -> " << static_cast<int>(token.getToken()) << endl;
        cout << "value -> " << token.getValue() << endl;
        cout << "numberString -> " << token.getNumberString() << endl;
        cout << endl;
    }

    return 0;
}