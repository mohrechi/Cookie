#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

char s[MAXN];
int l[MAXN], r[MAXN];

int main() {
    int n;
    gets(s + 1);
    for (n = 1; s[n]; ++n) {
        l[n] = l[n - 1];
        if ('a' <= s[n] and s[n] <= 'z') {
            ++l[n];
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        r[i] = r[i + 1];
        if ('A' <= s[i] and s[i] <= 'Z') {
            ++r[i];
        }
    }
    int ans = MAXN;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, l[i] + r[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
