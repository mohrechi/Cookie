class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int minVal = 1e100, secMinVal = 1e100;
        for (auto num : nums) {
            if (num > secMinVal) {
                return true;
            }
            if (num < minVal) {
                minVal = num;
            } else if (num > minVal && num < secMinVal) {
                secMinVal = num;
            }
        }
        return false;
    }
};
