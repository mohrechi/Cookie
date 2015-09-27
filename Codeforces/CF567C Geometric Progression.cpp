#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int main() {
    int n, k, a;
    while (scanf("%d%d", &n, &k) != EOF) {
        long long ans = 0;
        map<int, long long> cnt1;
        map<int, long long> cnt2;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a % k == 0) {
                ans += cnt2[a / k];
                cnt2[a] += cnt1[a / k];
            }
            ++cnt1[a];
        }
        cout << ans << endl;
    }
    return 0;
}
