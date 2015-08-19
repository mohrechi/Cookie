class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> nums;
        nums.insert(1);
        for (int i = 1; i < n; ++i) {
            long long cur = *nums.begin();
            nums.insert(cur * 2);
            nums.insert(cur * 3);
            nums.insert(cur * 5);
            nums.erase(cur);
        }
        return *nums.begin();
    }
};
