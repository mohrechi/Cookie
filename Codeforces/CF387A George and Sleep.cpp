#include <bits/stdc++.h>
using namespace std;

int input() {
    string s;
    cin >> s;
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 +
            (s[3] - '0') * 10 + (s[4] - '0');
}

int main() {
    int a = input();
    int b = input();
    if (a < b) {
        a += 24 * 60;
    }
    a -= b;
    cout << a / 60 / 10 << a / 60 % 10 << ":";
    cout << a % 60 / 10 << a % 60 % 10 << endl;
    return 0;
}
