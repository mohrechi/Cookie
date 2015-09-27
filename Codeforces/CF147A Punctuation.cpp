#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    ios::sync_with_stdio(false);
    getline(cin, s);
    string sub;
    vector<string> subs;
    for (int i = 0; i < (int)s.length(); ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            sub += s[i];
        } else {
            subs.push_back(sub);
            sub = "";
            if (s[i] != ' ') {
                sub += s[i];
                subs.push_back(sub);
                sub = "";
            }
        }
    }
    subs.push_back(sub);
    cout << subs[0];
    for (int i = 1; i < (int)subs.size(); ++i) {
        if ('a' <= subs[i][0] && subs[i][0] <= 'z') {
            cout << " ";
        }
        cout << subs[i];
    }
    cout << endl;
    return 0;
}
