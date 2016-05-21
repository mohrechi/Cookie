#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;

int main() {
    int T, N;
    int a[MAXN][MAXN];
    cin >> T;
    while (T--) {
        cin >> N;
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> a[i][j];
                if (i) {
                    if (j == 0) {
                        a[i][j] += a[i - 1][j];
                    } else if (j == i) {
                        a[i][j] += a[i - 1][j - 1];
                    } else {
                        a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
                    }
                }
                ans = max(ans, a[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
