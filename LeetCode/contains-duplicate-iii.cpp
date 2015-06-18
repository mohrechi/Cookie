class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (t < 0) {
            return false;
        }
        queue<int> q;
        multiset<long long> s;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (q.size() > k) {
                s.erase(s.find(q.front()));
                q.pop();
            }
            auto m = s.lower_bound(nums[i] - t);
            if (m != s.end() and abs(nums[i] - *m) <= t) {
                return true;
            }
            m = s.lower_bound(nums[i] + t);
            if (m != s.end() and abs(nums[i] - *m) <= t) {
                return true;
            }
            q.push(nums[i]);
            s.insert(nums[i]);
        }
        return false;
    }
};
