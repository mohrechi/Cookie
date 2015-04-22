#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 12) + 10;

int n, a[MAXN];
int ans;

int dfs(int x) {
    if (x >= (1 << n)) {
        return 0;
    }
    int l = dfs(x << 1) + a[x << 1];
    int r = dfs((x << 1) + 1) + a[(x << 1) + 1];
    ans += abs(l - r);
    return max(l, r);
}

int main() {
    cin >> n;
    for (int i = 2; i <= (1 << (n + 1)) - 1; ++i) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
