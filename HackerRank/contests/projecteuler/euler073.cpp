#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;

int D, A;
vector<int> facts[MAXN];

void initFactors() {
    for (int i = 2; i <= D; ++i) {
        if (facts[i].size() == 0U) {
            for (int j = i + i; j <= D; j += i) {
                facts[j].push_back(i);
            }
        }
    }
}

int getNum(int k, int x) {
    vector<int>& fact = facts[k];
    int n = (int)fact.size();
    int num = x;
    for (int i = 1; i < (1 << n); ++i) {
        int cnt = 0;
        int f = 1;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt += 1;
                f *= fact[j];
            }
        }
        f = x / f;
        if (cnt & 1) {
            num -= f;
        } else {
            num += f;
        }
    }
    return num;
}

int main() {
    cin >> A >> D;
    initFactors();
    long long ans = 0;
    for (int i = A + 1; i <= D; ++i) {
        int lower = i / (A + 1);
        int upper = i / A;
        if (i % A == 0) {
            --upper;
        }
        ans += getNum(i, upper) - getNum(i, lower);
    }
    cout << ans << endl;
    return 0;
}
