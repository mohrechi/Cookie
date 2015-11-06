class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int top = 0;
        vector<int> stk(nums.size());
        for (auto num : nums) {
            if (top == 0 || num > stk[top - 1]) {
                stk[top++] = num;
            } else {
                int l = 0, r = top - 1, pos = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (num > stk[mid]) {
                        pos = max(pos, mid);
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                stk[pos + 1] = num;
            }
        }
        return top;
    }
};
