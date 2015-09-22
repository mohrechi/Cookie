#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;

inline int encode(int a, int b) {
    return a * MAXN + b;
}

int main() {
    int n, m, a, b;
    map<int, int> da, db, ca, cb;
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d%d", &a, &b);
        ++da[b];
        ++ca[encode(a, b)];
    }
    while (m--) {
        scanf("%d%d", &a, &b);
        ++db[b];
        ++cb[encode(a, b)];
    }
    int d = 0;
    for (auto v : da) {
        d += min(v.second, db[v.first]);
    }
    int c = 0;
    for (auto v : ca) {
        c += min(v.second, cb[v.first]);
    }
    printf("%d %d\n", d, c);
    return 0;
}
