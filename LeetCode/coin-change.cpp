class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> nums(amount + 1, -1);
        nums[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (auto coin : coins) {
                if (coin <= i && nums[i - coin] != -1) {
                    if (nums[i] == -1 || nums[i] > nums[i - coin] + 1) {
                        nums[i] = nums[i - coin] + 1;
                    }
                }
            }
        }
        return nums[amount];
    }
};