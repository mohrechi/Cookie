#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, m = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        s += a;
        m = max(a, m);
    }
    printf("%d\n", m + s);
    return 0;
}
