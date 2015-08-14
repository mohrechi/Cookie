#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string, int> m;
    m["rock"] = 0;
    m["scissors"] = 1;
    m["paper"] = 2;
    int c[3];
    for (int i = 0; i < 3; ++i) {
        cin >> s;
        c[i] = m[s];
    }
    for (int i = 0; i < 3; ++i) {
        bool win = true;
        for (int j = 0; j < 3; ++j) {
            if (i != j) {
                if ((c[i] + 1) % 3 != c[j]) {
                    win = false;
                    break;
                }
            }
        }
        if (win) {
            switch (i) {
            case 0:
                puts("F");
                break;
            case 1:
                puts("M");
                break;
            case 2:
                puts("S");
                break;
            }
            return 0;
        }
    }
    puts("?");
    return 0;
}
