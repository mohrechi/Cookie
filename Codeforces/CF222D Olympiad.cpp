#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, x;
int a[MAXN], b[MAXN];

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    int largerNum = 0;
    for (int i = n - 1, j = 0; i >= 0 && j < n; --i) {
        while (j < n && a[i] + b[j] < x) {
            ++j;
        }
        if (j < n) {
            ++largerNum;
            ++j;
        }
    }
    printf("1 %d\n", largerNum);
    return 0;
}
