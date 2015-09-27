class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long target = n * (n + 1) / 2;
        for (auto num : nums) {
            sum += num;
        }
        return target - sum;
    }
};
