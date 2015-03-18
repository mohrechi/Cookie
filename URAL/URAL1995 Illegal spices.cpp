#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, k, p;
int w[MAXN];

int main() {
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n; ++i) {
        w[i] = 1;
    }
    int lowerNum = 0;
    int lastWeight = 1;
    for (int i = n - k; i < n; ++i) {
        if (lowerNum * 100 >= p * i) {
            w[i] = lastWeight;
        } else {
            lowerNum = i;
            w[i] = ++lastWeight;
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += w[i];
    }
    cout << sum << endl;
    for (int i = 0; i < n; ++i) {
        if (i) {
            putchar(' ');
        }
        printf("%d", w[i]);
    }
    putchar('\n');
    return 0;
}
