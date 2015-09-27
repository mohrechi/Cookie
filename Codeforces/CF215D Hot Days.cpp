#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, t, T, x, cost;
    scanf("%I64d%I64d", &n, &m);
    long long sum = 0;
    while (n--) {
        scanf("%I64d%I64d%I64d%I64d", &t, &T, &x, &cost);
        if (t + m <= T) {
            sum += cost;
        } else if (t >= T) {
            sum += x * m + cost;
        } else {
            sum += min(x * m + cost, (m + (T - t - 1)) / (T - t) * cost);
        }
    }
    printf("%I64d\n", sum);
    return 0;
}
