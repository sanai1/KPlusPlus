#include <vector>
#include <fstream>
#include <map>

#include "TokenImplementation.hpp"
#include "../starter/Starter.hpp"

#pragma once

class LexerImplementation {
public:

    vector<TokenImplementation> tokenize(string input) {
        this->input_ = std::move(input);
        this->position_ = 0;
        this->current_ = input_[0];

        vector<TokenImplementation> tokens;

        while (current_ != NULL) {
            if (current_ == ' ') {
                skipWhiteSpace();
            } else if ('a' <= current_ and current_ <= 'z') {
                tokens.emplace_back(getTokenImplementation());
            } else if ('0' <= current_ and current_ <= '9') {
                tokens.emplace_back(TokenTypeEnum::LITERAL, getNumber(), numberString_);
            } else if (current_ == '"' or to_string(current_) == "'") {
                tokens.emplace_back(TokenTypeEnum::LITERAL, getString(current_), numberString_);
            } else if (current_ == '+' or current_ == '-' or current_ == '*' or current_ == '/' or current_ == '%') {
                tokens.emplace_back(getArithmetics());
            } else if (current_ == '>' or current_ == '<' or current_ == '!' or current_ == '=') {
                tokens.emplace_back(getComparison());
            } else if (current_ == '(' or current_ == ')' or current_ == '[' or current_ == ']' or current_ == '{' or current_ == '}') {
                tokens.emplace_back(TokenTypeEnum::BRACKET, to_string(current_), numberString_);
                advance();
            } else if (current_ == ';' or current_ == ':' or current_ == ',' or current_ == '.') {
                tokens.emplace_back(TokenTypeEnum::PUNCTUATION, to_string(current_), numberString_);
                advance();
            } else if (current_ == '\n') {
                numberString_++;
                advance();
            } else {
                string str(1, current_);
                tokens.emplace_back(TokenTypeEnum::OTHER, str, numberString_);
                advance();
            }
        }
        tokens.emplace_back(TokenTypeEnum::END, to_string(current_), numberString_);
        return tokens;
    }

private:
    string input_;
    int position_;
    char current_;
    int numberString_ = 1;

    void advance() {
        position_++;
        if (position_ > input_.size()) {
            current_ = NULL;
        } else {
            current_ = input_[position_];
        }

    }

    void skipWhiteSpace() {
        while (current_ != NULL and current_ == ' ') {
            advance();
        }
    }

    TokenImplementation getTokenImplementation() {
        string result;
        while (current_ != NULL and (('0' <= current_ and current_ <= '9') or ('a' <= current_ and current_ <= 'z'))) {
            result += current_;
            advance();
        }
        if (Starter::getInstance().getBor().find(result)) {
            return {TokenTypeEnum::SERVICE_WORD, result, numberString_};
        }
        return {TokenTypeEnum::ID, result, numberString_};
    }

    TokenImplementation getArithmetics() {
        string result;
        result += current_;
        advance();
        return {TokenTypeEnum::OPERATION, result, numberString_};
    }

    TokenImplementation getComparison() {
        string result;
        result += current_;
        advance();
        if (result == "=") {
            if (current_ == '=') {
                result += current_;
                advance();
                return {TokenTypeEnum::COMPARISON, result, numberString_};
            } else {
                return {TokenTypeEnum::ASSIGMENT, result, numberString_};
            }
        } else if (result == "<" or result == ">") {
            if (current_ == '=') {
                result += current_;
                advance();
            }
            return {TokenTypeEnum::COMPARISON, result, numberString_};
        } else {
            if (current_ == '=') {
                result += current_;
                advance();
                return {TokenTypeEnum::COMPARISON, result, numberString_};
            } else {
                return {TokenTypeEnum::DENIAL, result, numberString_};
            }
        }
    }

    string getNumber() {
        string result;
        bool fl = false;
        while ((current_ != NULL and '0' <= current_ and current_ <= '9') or (current_ == '.' and !fl)) {
            if (current_ == '.') fl = true;
            result += current_;
            advance();
        }
        return result;
    }

    string getString(char type) {
        string result;
        advance();
        while (current_ != NULL and current_ != type) {
            result += current_;
            advance();
        }
        if (current_ == type) advance();
        return result;
    }

};