#pragma once

#include <iostream>

using namespace std;

class Bor {
public:
    void add(string &str) {
        Bor *bor = this;
        for (char c : str) {
            c -= 'a';
            if (!bor->to[c]) {
                bor->to[c] = new Bor();
            }

            bor = bor->to[c];
        }
        bor->terminal = true;
    }
    bool find(string &str) {
        Bor *bor = this;
        for (char c : str) {
            c -= 'a';
            if (!bor->to[c]) {
                return false;
            }
            bor = bor->to[c];
        }
        return bor->terminal;
    }
    bool erase(string &str) {
        Bor *bor = this;
        if (!bor->find(str)) {
            return false;
        }
        for (char c : str) {
            c -= 'a';
            bor = bor->to[c];
        }
        bor->terminal = false;
        return true;
    }
private:
    Bor* to[26] = {nullptr};
    bool terminal = false;
};
