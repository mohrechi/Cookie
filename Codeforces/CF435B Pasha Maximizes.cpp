#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i + 1 < (int)s.length() and k; ++i) {
        int pos = i;
        for (int j = i + 1; j < (int)s.length() and j <= i + k; ++j) {
            if (s[j] > s[pos]) {
                pos = j;
            }
        }
        for (int j = pos; j - 1 >= i and k; --j) {
            --k;
            swap(s[j], s[j - 1]);
        }
    }
    cout << s << endl;
    return 0;
}
