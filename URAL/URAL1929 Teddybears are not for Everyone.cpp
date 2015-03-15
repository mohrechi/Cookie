#include <bits/stdc++.h>
using namespace std;

long long C(int n, int m) {
    long long res = 1;
    for (int i = 0; i < m; ++i) {
        res *= (n - i);
    }
    for (int i = 2; i <= m; ++i) {
        res /= i;
    }
    return res;
}

int main() {
    int n, m, a;
    bool isHater = false;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &a);
        if (a == 1) {
            isHater = true;
            break;
        }
    }
    if (m < n / 3) {
        puts("0");
        return 0;
    }
    long long num = 0;
    if (isHater) {
        num += C(n - m, 2);
        if (m - 1 >= n / 3) {
            num += C(n - m, 1) * C(m - 1, 1);
        }
        if (m - 2 >= n / 3) {
            num += C(m - 1, 2);
        }
    } else {
        num += C(n - m - 1, 1) * C(m, 1);
        if (m - 1 >= n / 3) {
            num += C(m, 2);
        }
    }
    printf("%lld\n", num);
    return 0;
}
