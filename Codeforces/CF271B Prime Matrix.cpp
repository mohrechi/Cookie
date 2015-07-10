#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int MAXP = 1e5 + 100;

bool prime[MAXP];

void initPrime() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAXP; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < MAXP; j += i) {
                prime[j] = false;
            }
        }
    }
}

int n, m, a, c[MAXN][MAXN];

int main() {
    initPrime();
    cin >> n >> m;
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            while (not prime[a++]) {
                ++c[i][j];
            }
            sum += c[i][j];
        }
        ans = min(ans, sum);
    }
    for (int j = 0; j < m; ++j) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += c[i][j];
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
