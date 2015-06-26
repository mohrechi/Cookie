class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        for (int i = 1, j = 0, n = (int)nums.size(); i <= n; ++i) {
            if (i == n or nums[i] - nums[i - 1] != 1) {
                ranges.push_back(format(nums[j], nums[i - 1]));
                j = i;
            }
        }
        return ranges;
    }
private:
    string format(int left, int right) {
        char buf[128];
        if (left == right) {
            sprintf(buf, "%d", left);
        } else {
            sprintf(buf, "%d->%d", left, right);
        }
        return buf;
    }
};
