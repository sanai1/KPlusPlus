#include <iostream>
#include <fstream>
#include <sstream>

#include "../lexer/Bor.hpp"

#pragma once

using namespace std;

class Starter { // Singleton
public:
    static Starter& getInstance() {
        if (!INSTANCE) {
            INSTANCE = new Starter();
        }
        return *INSTANCE;
    }

    Bor getBor() {
        return bor_;
    }

    string getTextProgram() {
        return inputTextProgram_;
    }

    Starter(const Starter&) = delete;
    Starter& operator=(const Starter&) = delete;

private:
    Bor bor_;
    string inputTextProgram_;
    string fileProgramText_;
    string fileName_;
    static Starter* INSTANCE;

    void readProgram() {
        ifstream file(fileProgramText_);
        stringstream ss;
        ss << file.rdbuf();
        inputTextProgram_ = ss.str();
    }

    void fillBor() {
        string word;
        ifstream in(fileName_);
        if (in.is_open()) {
            while (getline(in, word)) {
                bor_.add(word);
            }
        }
        in.close();
    }

    Starter() {
        fileName_ = "ServiceWords.txt";
        fileProgramText_ = "testProgram.kpp";

        readProgram();
        fillBor();
    }

};