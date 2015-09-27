#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e7 + 5;

int num[MAXN];

int main() {
    int a, n;
    for (int i = 0; i < MAXN; ++i) {
        num[i] = i;
    }
    for (int i = 2; i * i < MAXN; ++i) {
        int inc = i * i;
        for (int j = inc, k = 1; j < MAXN; j += inc, ++k) {
            num[j] = k;
        }
    }
    scanf("%d%d", &a, &n);
    long long cnt = 0;
    for (int i = a; i < a + n; ++i) {
        cnt += num[i];
    }
    printf("%I64d\n", cnt);
    return 0;
}
