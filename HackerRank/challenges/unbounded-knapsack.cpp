#include <bits/stdc++.h>
using namespace std;
const int MAXK = 2000 + 5;

bool dp[MAXK];

int main() {
    int T, N, M;
    scanf("%d", &T);
    while (T--) {
        int a;
        scanf("%d%d", &N, &M);
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        while (N--) {
            scanf("%d", &a);
            if (dp[M]) {
                continue;
            }
            for (int i = 0; i < M; ++i) {
                if (dp[i] && i + a <= M) {
                    dp[i + a] = true;
                }
            }
        }
        for (int i = M; i >= 0; --i) {
            if (dp[i]) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
