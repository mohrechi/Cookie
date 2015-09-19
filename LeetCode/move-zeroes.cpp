class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i]) {
                nums[k++] = nums[i];
            }
        }
        for (; k < (int)nums.size(); ++k) {
            nums[k] = 0;
        }
    }
};
