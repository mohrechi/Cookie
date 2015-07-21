#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e4 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN], l[MAXN], r[MAXN];
int fact[MAXM][64], factNum[MAXM];

void initFactor() {
    for (int i = 1; i < MAXM; ++i) {
        for (int j = i; j < MAXM; j += i) {
            fact[j][factNum[j]++] = i;
        }
    }
}

vector<int> nums[MAXM];

int main() {
    initFactor();
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < MAXM; ++i) {
            nums[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            l[i] = 0;
            r[i] = n + 1;
            nums[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < factNum[a[i]]; ++j) {
                int f = fact[a[i]][j];
                for (int k = 0; k < (int)nums[f].size(); ++k) {
                    int p = nums[f][k];
                    if (p < i) {
                        l[i] = max(l[i], p);
                    }
                    if (p > i) {
                        r[i] = min(r[i], p);
                    }
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += 1LL * (i - l[i]) * (r[i] - i);
        }
        cout << ans % MOD << endl;
    }
    return 0;
}
