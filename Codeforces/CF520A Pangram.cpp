#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        map<char, int> num;
        for (auto c : s) {
            ++num[c];
        }
        bool valid = true;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (num[c] == 0 && num[c - 'a' + 'A'] == 0) {
                valid = false;
                break;
            }
        }
        cout << (valid ? "YES" : "NO") << endl;
    }
    return 0;
}
