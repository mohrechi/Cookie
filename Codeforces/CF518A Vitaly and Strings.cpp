#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = s.length() - 1; i >= 0; --i) {
        s[i] += 1;
        if (s[i] > 'z') {
            if (i) {
                s[i] = 'a';
            }
        } else {
            break;
        }
    }
    if (s < t) {
        cout << s << endl;
    } else {
        cout << "No such string" << endl;
    }
    return 0;
}
