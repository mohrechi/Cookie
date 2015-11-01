#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    long long a = 1, b = 1;
    while (n--) {
        (a *= 27) %= MOD;
        (b *= 7) %= MOD;
    }
    cout << (a - b + MOD) % MOD << endl;
    return 0;
}
