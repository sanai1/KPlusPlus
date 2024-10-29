#pragma once

#include <iostream>
#include <fstream>

#include "Bor.hpp"

using namespace std;

const string fileName = "ServiceWords.txt";
Bor bor = Bor();

int main() {
    string word;
    ifstream in(fileName);
    if (in.is_open()) {
        while (getline(in, word)) {
            bor.add(word);
            cout << bor.find(word);
        }
    }
    in.close();



    return 0;
}