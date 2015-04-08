#include <bits/stdc++.h>
using namespace std;

long long expo[20];

void dfs(vector<long long> &a,
         map<long long, map<int, int>> &num,
         int index,
         long long sum,
         int stickNum,
         int k) {
    if (index == a.size()) {
        ++num[sum][stickNum];
        return;
    }
    dfs(a, num, index + 1, sum, stickNum, k);
    dfs(a, num, index + 1, sum + a[index], stickNum, k);
    if (a[index] < 20 && stickNum < k) {
        dfs(a, num, index + 1, sum + expo[a[index]], stickNum + 1, k);
    }
}

map<long long, map<int, int>> getCombination(vector<long long> &a, int k) {
    map<long long, map<int, int>> num;
    dfs(a, num, 0, 0, 0, k);
    return num;
}

int main() {
    int n, k;
    long long S;
    expo[0] = 1;
    for (int i = 1; i < 20; ++i) {
        expo[i] = i * expo[i - 1];
    }
    while (cin >> n >> k >> S) {
        vector<long long> a(n >> 1);
        vector<long long> b(n - (n >> 1));
        for (int i = 0; i < (n >> 1); ++i) {
            cin >> a[i];
        }
        for (int i = (n >> 1); i < n; ++i) {
            cin >> b[i - (n >> 1)];
        }
        auto numA = getCombination(a, k);
        auto numB = getCombination(b, k);
        long long ans = 0;
        for (auto sum : numA) {
            for (auto it : sum.second) {
                for (int i = 0; i <= k - it.first; ++i) {
                    ans += 1LL * it.second * numB[S - sum.first][i];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
