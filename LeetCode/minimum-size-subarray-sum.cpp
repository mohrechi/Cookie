class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minLen = 0;
        for (int l = 0, r = 0, sum = 0; ; ++l) {
            while (sum < s and r < (int)nums.size()) {
                sum += nums[r];
                ++r;
            }
            if (sum >= s) {
                if (minLen == 0 or r - l < minLen) {
                    minLen = r - l;
                }
            } else {
                break;
            }
            sum -= nums[l];
        }
        return minLen;
    }
};