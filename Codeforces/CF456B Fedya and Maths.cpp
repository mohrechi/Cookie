#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int main() {
    int a = '0', b = '0';
    char ch;
    while (true) {
        ch = getchar();
        if ('0' <= ch && ch <= '9') {
            a = b;
            b = ch;
        } else {
            break;
        }
    }
    int num = (a - '0') * 10 + b - '0';
    cout << (num % 4 ? 0 : 4) << endl;
    return 0;
}
