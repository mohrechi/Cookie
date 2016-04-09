#include <bits/stdc++.h>
using namespace std;
const int MAXN = 16;
const int MAXM = 10000000;

int n, m[MAXN], r[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &r[i]);
    }
    int cnt = 0;
    for (int i = 0; i < MAXM; ++i) {
        bool flag = false;
        for (int j = 0; j < n; ++j) {
            if (i % m[j] == r[j]) {
                flag = true;
                break;
            }
        }
        cnt += flag;
    }
    printf("%.6f\n", 1.0 * cnt / MAXM);
    return 0;
}
