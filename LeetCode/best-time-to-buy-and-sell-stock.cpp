class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0;
        if (prices.size() > 0) {
            int minPrice = prices[0];
            for (int i = 1; i < prices.size(); ++i) {
                ans = max(ans, prices[i] - minPrice);
                minPrice = min(minPrice, prices[i]);
            }
        }
        return ans;
    }
};
