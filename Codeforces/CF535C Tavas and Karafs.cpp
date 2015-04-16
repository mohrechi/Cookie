#include <bits/stdc++.h>
using namespace std;

long long A, B;

inline long long getNumAt(const long long &i) {
    return A + (i - 1) * B;
}

int main() {
    long long n, l, t, m;
    while (cin >> A >> B >> n) {
        while (n--) {
            cin >> l >> t >> m;
            long long start = l;
            long long r = l + t * m;
            long long ans = -1;
            while (l <= r) {
                long long mid = (l + r) >> 1;
                long long sum = (getNumAt(start) + getNumAt(mid)) * (mid - start + 1) / 2;
                if (getNumAt(mid) <= t && sum <= t * m) {
                    ans = max(ans, mid);
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
