#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;


int main() {
    int T, N, a;
    cin >> T;
    while (T--) {
        cin >> N;
        int dp = 0;
        int ans1 = -MAXN;
        int ans2 = 0;
        bool positive = false;
        int maxNegative = -MAXN;
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &a);
            dp = max(a, dp + a);
            ans1 = max(ans1, dp);
            if (a >= 0) {
                positive = true;
                ans2 += a;
            } else {
                maxNegative = max(maxNegative, a);
            }
        }
        if (!positive) {
            ans2 = maxNegative;
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
