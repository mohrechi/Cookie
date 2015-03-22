class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (k >= prices.size() / 2) {
            return fast(prices);
        }
        int ans = 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        int curr = 1;
        for (int j = 1; j <= k; ++j) {
            int maxDiff = -prices[0];
            int prev = 1 - curr;
            for (int i = 1; i < prices.size(); ++i) {
                dp[i][curr] = max(dp[i][prev], max(dp[i-1][curr], prices[i] + maxDiff));
                maxDiff = max(maxDiff, dp[i-1][prev] - prices[i]);
            }
            curr = prev;
        }
        return dp[prices.size()-1][1-curr];
    }
private:
    int fast(vector<int> &prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                sum += prices[i] - prices[i - 1];
            }
        }
        return sum;
    }
};
