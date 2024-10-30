#include <iostream>

#include "../lexer/LexerImplementation.hpp"
#include "Starter.hpp"

using namespace std;

Starter* Starter::INSTANCE = nullptr;

int main() {
    LexerImplementation lexer = LexerImplementation();
    vector<TokenImplementation> tokens = lexer.tokenize(Starter::getInstance().getTextProgram());

    for (auto & token : tokens) {
        cout << "TokenType -> " << static_cast<int>(token.getToken()) << endl;
        cout << "value -> " << token.getValue() << endl;
        cout << "numberString -> " << token.getNumberString() << endl;
        cout << endl;
    }

    return 0;
}