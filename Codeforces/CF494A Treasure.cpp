#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n;
char s[MAXN];

int main() {
    scanf("%s", s);
    n = strlen(s);
    int last = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '#') {
            last = i;
            break;
        }
    }
    int cnt = 0, cntL = 0;
    for (int i= 0; i < last; ++i) {
        switch (s[i]) {
        case '(':
            ++cntL;
            break;
        case ')':
            --cntL;
            break;
        case '#':
            ++cnt, --cntL;
            break;
        }
        if (cntL < 0) {
            break;
        }
    }
    int cntR = 0;
    for (int i = n - 1; i > last; --i) {
        if (s[i] == '(') {
            --cntR;
        } else {
            ++cntR;
        }
        if (cntR < 0) {
            break;
        }
    }
    if (cntL < 0 || cntR < 0 || cntL - cntR < 1) {
        cout << -1 << endl;
    } else {
        while (cnt--) {
            cout << 1 << endl;
        }
        cout << cntL - cntR << endl;
    }
    return 0;
}
