class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long upper = 1;
        int idx = 0, ret = 0;
        while (upper <= n) {
            if (idx < (int)nums.size() && nums[idx] <= upper) {
                upper += nums[idx++];
            } else {
                upper += upper;
                ++ret;
            }
        }
        return ret;
    }
};
