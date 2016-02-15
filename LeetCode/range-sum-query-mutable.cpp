class NumArray {
public:
    NumArray(vector<int> &nums) {
        this->nums = vector<int>(nums.size() + 1, 0);
        this->sums = vector<int>(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); ++i) {
            this->nums[i + 1] = nums[i];
            updateSum(i + 1, nums[i]);
        }
    }

    void update(int i, int val) {
        ++i;
        updateSum(i, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return querySum(j + 1) - querySum(i);
    }
private:
    vector<int> nums;
    vector<int> sums;
    
    inline int lowbit(int x) {
        return x & (-x);
    }
    
    void updateSum(int x, int val) {
        while (x < (int)sums.size()) {
            sums[x] += val;
            x += lowbit(x);
        }
    }
    
    int querySum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += sums[x];
            x -= lowbit(x);
        }
        return sum;
    }
};
