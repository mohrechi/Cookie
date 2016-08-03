class Solution {
public:
    int getMoneyAmount(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return get(1, n);
    }
private:
    vector<vector<int>> dp;
    int get(int l, int r) {
        if (l >= r) {
            return 0;
        }
        if (dp[l][r] >= 0) {
            return dp[l][r];
        }
        dp[l][r] = min(l + get(l + 1, r), get(l, r - 1) + r);
        for (int i = l + 1; i <= r - 1; ++i) {
            dp[l][r] = min(dp[l][r], i + max(get(l, i - 1), get(i + 1, r)));
        }
        return dp[l][r];
    }
};
