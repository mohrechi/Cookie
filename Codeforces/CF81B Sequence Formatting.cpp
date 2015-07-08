#include <bits/stdc++.h>
using namespace std;

char in[65536], out[65536];

inline bool isDigit(char c) {
    return '0' <= c and c <= '9';
}

int main() {
    bool lastIsDigit = false;
    bool lastIsNum = false;
    gets(in);
    int n = 0;
    for (int i = 0; in[i]; ++i) {
        if (isDigit(in[i])) {
            if (lastIsNum) {
                out[n++] = ' ';
                lastIsNum = false;
            }
            out[n++] = in[i];
            lastIsDigit = true;
        } else {
            if (lastIsDigit) {
                lastIsNum = true;
            }
            if (in[i] != ' ') {
                lastIsNum = false;
            }
            lastIsDigit = false;
            if (in[i] == ',') {
                out[n++] = ',';
                out[n++] = ' ';
            } else if (in[i] == '.') {
                i += 2;
                out[n++] = ' ';
                out[n++] = '.';
                out[n++] = '.';
                out[n++] = '.';
            }
        }
    }
    if (out[n - 1] == ' ') {
        --n;
    }
    for (int i = (out[0] == ' ' ? 1 : 0); i < n; ++i) {
        if (i and out[i] == ' ' and out[i - 1] == ' ') {
            continue;
        }
        putchar(out[i]);
    }
    return 0;
}
