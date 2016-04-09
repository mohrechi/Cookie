#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == 'A') {
            ++cnt;
        } else if (s[i] == '1') {
            cnt += 10;
            ++i;
        } else {
            cnt += s[i] - '0';
        }
    }
    cout << cnt << endl;
    return 0;
}
