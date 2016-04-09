#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (auto c : s) {
        if ('A' <= c && c <= 'Z') {
            sum += c - 'A' + 1;
        } else if ('a' <= c && c <= 'z') {
            sum -= c - 'a' + 1;
        }
    }
    cout << sum << endl;
    return 0;
}
