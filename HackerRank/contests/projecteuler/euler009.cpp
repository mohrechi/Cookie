#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        long long ans = -1;
        for (int a = 1; a < N; ++a) {
            int u = N * N - 2 * N * a;
            int d = 2 * (N - a);
            if (u % d == 0) {
                int b = u / d;
                int c = N - a - b;
                if (a < b) {
                    ans = max(ans, 1LL * a * b * c);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
