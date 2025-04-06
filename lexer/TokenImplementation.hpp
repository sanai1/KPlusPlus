#include <iostream>

#include "TokenTypeEnum.hpp"

#pragma once

using namespace std;

class TokenImplementation {
public:

    TokenImplementation(TokenTypeEnum typeEnum, string value, int numberString) :
            type_(typeEnum),
            value_(std::move(value)),
            numberString_(numberString) {}

    TokenTypeEnum getToken() {
        return type_;
    }

    string getValue() {
        return value_;
    }

    int getNumberString() {
        return numberString_;
    }

private:
    const TokenTypeEnum type_;
    const string value_;
    const int numberString_;

};