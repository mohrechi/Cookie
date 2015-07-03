class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        int cnt0 = 0, cnt1 = 0;
        int can0, can1;
        for (auto num : nums) {
            if (cnt0 and num == can0) {
                ++cnt0;
            } else if (cnt1 and num == can1) {
                ++cnt1;
            } else if (cnt0 == 0) {
                cnt0 = 1;
                can0 = num;
            } else if (cnt1 == 0) {
                cnt1 = 1;
                can1 = num;
            } else {
                --cnt0;
                --cnt1;
            }
        }
        vector<int> ans;
        if (cnt0) {
            cnt0 = 0;
            for (auto num : nums) {
                if (num == can0) {
                    ++cnt0;
                }
            }
            if (cnt0 > (int)nums.size() / 3) {
                ans.push_back(can0);
            }
        }
        if (cnt1) {
            cnt1 = 0;
            for (auto num : nums) {
                if (num == can1) {
                    ++cnt1;
                }
            }
            if (cnt1 > (int)nums.size() / 3) {
                ans.push_back(can1);
            }
        }
        return ans;
    }
};
