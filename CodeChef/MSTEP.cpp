#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;

int N, x[MAXN * MAXN], y[MAXN * MAXN];

int main() {
    int T, a;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                scanf("%d", &a);
                x[a] = i;
                y[a] = j;
            }
        }
        int ans = 0;
        for (int i = N * N; i > 1; --i) {
            ans += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
