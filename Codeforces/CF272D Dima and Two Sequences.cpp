#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, m;
vector<pair<int, int>> p;
long long fact[MAXN];
int two[MAXN];

int main() {
    int a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        p.push_back({a, i});
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b);
        p.push_back({b, i});
    }
    scanf("%d", &m);
    p.push_back({1e9 + 7, n + 7});
    sort(p.begin(), p.end());
    int lastX = -1, lastY = 0, cnt = 1, same = 0;
    map<int, int> facts;
    for (int i = 0; i < (int)p.size(); ++i) {
        if (p[i].first == lastX) {
            ++cnt;
            if (p[i].second == lastY) {
                ++same;
            }
        } else {
            if (cnt > 1) {
                ++facts[cnt];
            }
            cnt = 1;
        }
        lastX = p[i].first;
        lastY = p[i].second;
    }
    fact[0] = 1;
    two[0] = 0;
    for (int i = 1; i <= (n * 2); ++i) {
        int tmp = i;
        two[i] = two[i - 1];
        while ((tmp & 1) == 0) {
            ++two[i];
            tmp >>= 1;
        }
        fact[i] = fact[i - 1] * tmp % m;
    }
    long long twoCnt = 0;
    long long ans = 1;
    for (auto f : facts) {
        twoCnt += (long long)two[f.first] * f.second;
        for (int i = 0; i < f.second; ++i) {
            ans = ans * fact[f.first] % m;
        }
    }
    twoCnt -= same;
    long long base = 2;
    for (int i = 0; (1LL << i) <= twoCnt; ++i) {
        if (twoCnt & (1LL << i)) {
            ans = ans * base % m;
        }
        base = base * base % m;
    }
    cout << ans << endl;
    return 0;
}
