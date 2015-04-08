#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;

struct Node {
    int earn1;
    int earn2;
};

int n, m, k;
Node dp[MAXN][2];

Node get(int n, int p) {
    if (dp[n][p].earn1 != -1) {
        return dp[n][p];
    }
    if (n == 0) {
        return dp[n][p] = {0, 0};
    }
    if (k > n) {
        dp[n][p] = {m, 0};
    }
    for (int i = 1; i <= min(k, n); ++i) {
        Node temp = get(n - i, 1 - p);
        if (dp[n][p].earn1 == -1 ||
            dp[n][p].earn1 < temp.earn2 + i ||
            dp[n][p].earn1 < temp.earn2 + i || dp[n][p].earn2 > temp.earn1) {
            dp[n][p] = {temp.earn2 + i, temp.earn1};
        }
    }
    return dp[n][p];
}

int main() {
    while (cin >> n >> m >> k) {
        memset(dp, -1, sizeof(dp));
        auto node = get(n, 0);
        cout << node.earn1 << " " << node.earn2 << endl;
    }
    return 0;
}
