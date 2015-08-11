#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000 + 10;
const int MOD = 1e9 + 7;

int c[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    c[1][1] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i == 1 && j == 1) {
                continue;
            }
            if (j == 1) {
                c[i][j] = c[i - 1][i - 1];
                continue;
            }
            c[i][j] = (c[i][j - 1] + c[i - 1][j - 1]) % MOD;
        }
    }
    cout << c[n + 1][n] << endl;
	return 0;
}
