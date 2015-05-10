#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    string s;
    while (cin >> k >> s) {
        set<char> cs;
        for (auto c : s) {
            cs.insert(c);
        }
        if (k > cs.size()) {
            cout << "NO" << endl;
        } else {
            cout << "YES";
            cs.clear();
            int num = 0;
            for (auto c : s) {
                if (num < k and cs.find(c) == cs.end()) {
                    ++num;
                    cs.insert(c);
                    cout << endl;
                }
                cout << c;
            }
            cout << endl;
        }
    }
    return 0;
}
