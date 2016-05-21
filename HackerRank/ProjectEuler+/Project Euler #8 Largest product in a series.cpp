#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, K, N;
    string s;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        cin >> s;
        int ans = 0;
        for (int i = 0; i <= (int)s.length() - K; ++i) {
            int num = 1;
            for (int j = 0; j < K; ++j) {
                num *= s[i + j] - '0';
            }
            ans = max(ans, num);
        }
        cout << ans << endl;
    }
    return 0;
}
