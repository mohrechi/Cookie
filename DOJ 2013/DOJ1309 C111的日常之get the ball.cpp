#include <bits/stdc++.h>
using namespace std;
const int MAXN = 35;

int num[MAXN][MAXN];

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        memset(num, 0, sizeof(num));
        num[0][0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                num[i][j] = num[i - 1][(j - 1 + n) % n] + num[i - 1][(j + 1) % n];
            }
        }
        cout << num[m][0] << endl;
    }
    return 0;
}
