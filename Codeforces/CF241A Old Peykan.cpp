#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int m, k;
int d[MAXN], s[MAXN];

int main() {
    while (scanf("%d%d", &m, &k) != EOF) {
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &d[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &s[i]);
        }
        int fuel = 0;
        int maxSupply = 0;
        int t = 0;
        for (int i = 1; i <= m; ++i) {
            maxSupply = max(maxSupply, s[i]);
            fuel += s[i];
            while (fuel < d[i]) {
                fuel += maxSupply;
                t += k;
            }
            fuel -= d[i];
            t += d[i];
        }
        cout << t << endl;
    }
    return 0;
}
