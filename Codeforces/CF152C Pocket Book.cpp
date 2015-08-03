#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MOD = 1e9 + 7;

int n, m;
char s[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
    long long ans = 1;
    for (int j = 1; j <= m; ++j) {
        set<char> st;
        for (int i = 1; i <= n; ++i) {
            st.insert(s[i][j]);
        }
        ans = (ans * (int)st.size()) % MOD;
    }
    cout << ans << endl;
    return 0;
}
