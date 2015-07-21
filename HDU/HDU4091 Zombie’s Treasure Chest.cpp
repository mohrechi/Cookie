#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long x, long long y) {
    return y == 0 ? x : gcd(y, x % y);
}

long long lcm(long long x, long long y) {
    return x / gcd(x, y) * y;
}

int main() {
    int T;
    long long N, S1, V1, S2, V2;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N >> S1 >> V1 >> S2 >> V2;
        long long m = lcm(S1, S2);
        long long num = N / m;
        if (num) {
            --num;
        }
        N -= num * m;
        if (V1 * S2 < V2 * S1) {
            swap(V1, V2);
            swap(S1, S2);
        }
        long long base = num * m / S1 * V1;
        if (S1 < S2) {
            swap(V1, V2);
            swap(S1, S2);
        }
        long long ans = 0;
        for (int i = 0; i * S1 <= N; ++i) {
            ans = max(ans, i * V1 + (N - i * S1) / S2 * V2);
        }
        cout << "Case #" << t << ": " << ans + base << endl;
    }
    return 0;
}
