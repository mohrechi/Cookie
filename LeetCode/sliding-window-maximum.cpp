class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<pair<int, int>> dq;
        for (int i = 0; i < (int)nums.size(); ++i) {
            while (dq.size() > 0 and nums[i] > dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
            if (i >= k - 1) {
                while (dq.front().second + k <= i) {
                    dq.pop_front();
                }
                ret.push_back(dq.front().first);
            }
        }
        return ret;
    }
};
