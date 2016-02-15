class NumArray {
public:
    NumArray(vector<int> &nums) {
        sums = vector<int>(nums.size() + 1, 0);
        for (int i = 1; i <= (int)nums.size(); ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};
