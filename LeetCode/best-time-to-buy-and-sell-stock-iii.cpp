class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int ans = 0;
        vector<int> leftPrices(prices.size());
        vector<int> rightPrices(prices.size());
        int minPrice = prices[0];
        leftPrices[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            leftPrices[i] = max(leftPrices[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        int maxPrice = prices[prices.size() - 1];
        rightPrices[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            rightPrices[i] = max(rightPrices[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }
        for (int i = 0; i < prices.size(); ++i) {
            ans = max(ans, leftPrices[i] + rightPrices[i]);
        }
        return ans;
    }
};
