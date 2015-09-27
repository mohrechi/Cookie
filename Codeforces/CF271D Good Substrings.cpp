#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1510;
const long long HASH_BASE = 17592186044423LL;

int n, k;
char s[MAXN], tmp[27];
bool bad[127];
int cnt[MAXN];
long long has[MAXN], base[MAXN];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    scanf("%s", tmp);
    for (int i = 0; i < 26; ++i) {
        bad[i + 'a'] = tmp[i] == '0';
    }
    scanf("%d", &k);
    base[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = cnt[i - 1] + bad[(int)s[i]];
        base[i] = base[i - 1] * HASH_BASE;
        has[i] = has[i - 1] + base[i] * s[i];
    }
    set<long long> se;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (cnt[j] - cnt[i - 1] <= k) {
                se.insert((has[j] - has[i - 1]) * base[n - i]);
            }
        }
    }
    cout << se.size() << endl;
    return 0;
}
