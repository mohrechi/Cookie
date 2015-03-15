#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    scanf("%lld", &n);
    m = n * (n - 3) / 2;
    switch (n) {
    case 4:
        puts("0 2");
        break;
    case 5:
        puts("0 0");
        break;
    case 6:
        puts("6 9");
        break;
    default:
        if (n & 1) {
            printf("%lld 0\n", m);
        } else {
            printf("%lld %lld\n", m, m);
        }
    }
    return 0;
}
