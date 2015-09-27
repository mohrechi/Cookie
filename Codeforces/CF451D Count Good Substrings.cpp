#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

char s[MAXN];
int num[MAXN][2][2];

int main() {
    while (scanf("%s", s) != EOF) {
        int n = strlen(s);
        memset(num[n], 0, sizeof(num[n]));
        for (int i = n - 1; i >= 0; --i) {
            for (int a = 0; a < 2; ++a) {
                for (int b = 0; b < 2; ++b) {
                    num[i][a][b] = num[i + 1][a][b];
                }
            }
            ++num[i][s[i] == 'b'][i & 1];
        }
        long long evenNum = 0, oddNum = 0;
        for (int i = 0; i < n; ++i) {
            evenNum += num[i + 1][s[i] == 'b'][(i & 1) ^ 1];
            oddNum += num[i][s[i] == 'b'][i & 1];
        }
        cout << evenNum << " " << oddNum << endl;
    }
    return 0;
}
