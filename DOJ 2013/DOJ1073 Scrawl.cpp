#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

long long pow(long long x, long long y) {
    long long res = 1;
    while(y--) {
        res = (res * x) % MOD;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m, a;
        set<int> p1, p2, p;
        set<int> g1, g2, g;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            p1.insert(a);
            p.insert(a);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a);
            g1.insert(a);
            g.insert(a);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            p2.insert(a);
            p.insert(a);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a);
            g2.insert(a);
            g.insert(a);
        }
        int common = g1.size() + g2.size() - g.size();
        long long num1 = pow(p1.size() + 1, g1.size() - common);
        long long num2 = pow(p2.size() + 1, g2.size() - common);
        long long num = pow(p.size() + 1, common);
        long long ans = (num1 * num2) % MOD;
        ans = (ans * num) % MOD;
        printf("%lld\n", ans);
    }
    return 0;
}
