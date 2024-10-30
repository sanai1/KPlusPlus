#pragma once

#include <utility>
#include <vector>
#include <fstream>
#include "TokenImplementation.hpp"
#include "Bor.hpp"

const string fileName = "ServiceWords.txt";
Bor bor = Bor();

class LexerImplementation {
public:

    vector<TokenImplementation> tokenize(string input) {
        this->input_ = std::move(input);
        this->position_ = 0;
        this->current_ = input_[0];

        vector<TokenImplementation> tokens;
        completionBor();

        while (current_ != NULL) {
            if (current_ == ' ') {
                skipWhiteSpace();
            } else if ('a' <= current_ and current_ <= 'z') {
                tokens.emplace_back(getTokenImplementation());
            } else if ('0' <= current_ and current_ <= '9') {
                tokens.emplace_back(TokenTypeEnum::NUMBER_LITERAL, getNumber(), numberString_);
            } else if ('"' == current_ or current_ <= '\'') {
                tokens.emplace_back(TokenTypeEnum::STRING_LITERAL, getString(current_), numberString_);
            } else if (current_ == '+') {
                tokens.emplace_back(getPlus());
            }  else if (current_ == '-') {
                tokens.emplace_back(getMinus());
            } else if (current_ == '*') {
                tokens.emplace_back(getMultiply());
            } else if (current_ == '/') {
                tokens.emplace_back(getDivision());
            } else if (current_ == '%') {
                tokens.emplace_back(getPercent());
            } else if (current_ == '=') {
                tokens.emplace_back(getAssign());
            } else if (current_ == '(') {
                tokens.emplace_back(TokenTypeEnum::LPAREN, "(", numberString_);
                advance();
            } else if (current_ == ')') {
                tokens.emplace_back(TokenTypeEnum::RPAREN, ")", numberString_);
                advance();
            } else if (current_ == '[') {
                tokens.emplace_back(TokenTypeEnum::LSQUAREBRACKET, "[", numberString_);
                advance();
            } else if (current_ == ']') {
                tokens.emplace_back(TokenTypeEnum::RSQUAREBRACKET, "]", numberString_);
                advance();
            } else if (current_ == '{') {
                tokens.emplace_back(TokenTypeEnum::LCURLYBRACE, "{", numberString_);
                advance();
            } else if (current_ == '}') {
                tokens.emplace_back(TokenTypeEnum::RCURLYBRACE, "}", numberString_);
                advance();
            } else if (current_ == ';') {
                tokens.emplace_back(TokenTypeEnum::SEMICOLON, ";", numberString_);
                advance();
            } else if (current_ == ':') {
                tokens.emplace_back(TokenTypeEnum::COLON, ":", numberString_);
                advance();
            } else if (current_ == ',') {
                tokens.emplace_back(TokenTypeEnum::COMMA, ",", numberString_);
                advance();
            } else {
                tokens.emplace_back(TokenTypeEnum::OTHER, to_string(current_), numberString_);
                advance();
            }
        }
//        tokens.emplace_back(TokenTypeEnum::END, current_, numberString_);
        return tokens;
    }

private:
    string input_;
    int position_;
    char current_;
    int numberString_ = 0;

    void advance() {
        position_ ++;
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
        if (bor.find(result)) {
            return {TokenTypeEnum::SERVICE_WORD, result, numberString_};
        }
        return {TokenTypeEnum::ID, result, numberString_};
    }

    TokenImplementation getPlus() {
        string result;
        result += current_;
        advance();
        if (current_ != NULL) {
            if (current_ == '+') {
                result += current_;
                advance();
                return {TokenTypeEnum::PLUSPLUS, result, numberString_};
            } else if (current_ == '=') {
                result += current_;
                advance();
                return {TokenTypeEnum::PLUSASSIGN, result, numberString_};
            }
        }
        return {TokenTypeEnum::PLUS, result, numberString_};
    }

    TokenImplementation getMinus() {
        string result;
        result += current_;
        advance();
        if (current_ != NULL) {
            if (current_ == '-') {
                result += current_;
                advance();
                return {TokenTypeEnum::MINUSMINUS, result, numberString_};
            } else if (current_ == '=') {
                result += current_;
                advance();
                return {TokenTypeEnum::MINUSASSIGN, result, numberString_};
            }
        }
        return {TokenTypeEnum::MINUS, result, numberString_};
    }

    TokenImplementation getMultiply() {
        string result;
        result += current_;
        advance();
        if (current_ != NULL) {
            if (current_ == '*') {
                result += current_;
                advance();
                return {TokenTypeEnum::MULTIPLYMULTIPLY, result, numberString_};
            } else if (current_ == '=') {
                result += current_;
                advance();
                return {TokenTypeEnum::MULTIPLYASSIGN, result, numberString_};
            }
        }
        return {TokenTypeEnum::MULTIPLY, result, numberString_};
    }

    TokenImplementation getDivision() {
        string result;
        result += current_;
        advance();
        if (current_ == '=') {
            result += current_;
            advance();
            return {TokenTypeEnum::DIVISIONASSIGN, result, numberString_};
        }
        return {TokenTypeEnum::DIVISION, result, numberString_};
    }

    TokenImplementation getPercent() {
        string result;
        result += current_;
        advance();
        if (current_ == '=') {
            result += current_;
            advance();
            return {TokenTypeEnum::PERCENTASSIGN, result, numberString_};
        }
        return {TokenTypeEnum::PERCENT, result, numberString_};
    }

    TokenImplementation getAssign() {
        string result;
        result += current_;
        advance();
        if (current_ == '=') {
            result += current_;
            advance();
            return {TokenTypeEnum::ASSIGNASSIGN, result, numberString_};
        }
        return {TokenTypeEnum::ASSIGN, result, numberString_};
    }

    string getNumber() {
        string result;
        while (current_ != NULL and '0' <= current_ and current_ <= '9') {
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

    static void completionBor() {
        string word;
        ifstream in(fileName);
        if (in.is_open()) {
            while (getline(in, word)) {
                bor.add(word);
            }
        }
        in.close();
    }

};