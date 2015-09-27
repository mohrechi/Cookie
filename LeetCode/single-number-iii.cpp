class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        for (auto num : nums) {
            xorSum ^= num;
        }
        int bit = 0;
        while ((xorSum & (1 << bit)) == 0) {
            ++bit;
        }
        int num0 = 0, num1 = 0;
        for (auto num : nums) {
            if (num & (1 << bit)) {
                num0 ^= num;
            } else {
                num1 ^= num;
            }
        }
        return {num0, num1};
    }
};
