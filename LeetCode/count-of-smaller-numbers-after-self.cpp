class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }
        int n = 0;
        map<int, int> pos;
        for (auto num : s) {
            pos[num] = ++n;
        }
        vector<int> bits(n + 1);
        vector<int> ans(nums.size());
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            ans[i] = query(bits, pos[nums[i]] - 1);
            update(bits, pos[nums[i]]);
        }
        return ans;
    }
private:
    inline int lowbit(int x) {
        return x & (-x);
    }
    void update(vector<int>& bits, int pos) {
        while (pos < (int)bits.size()) {
            ++bits[pos];
            pos += lowbit(pos);
        }
    }
    int query(vector<int>& bits, int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += bits[pos];
            pos -= lowbit(pos);
        }
        return ret;
    }
};
