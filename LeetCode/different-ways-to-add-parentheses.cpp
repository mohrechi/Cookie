class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums;
        vector<char> ops;
        int num = 0;
        bool isNum = false;
        for (int i = 0; i <= (int)input.size(); ++i) {
            if (i == (int)input.size() || !('0' <= input[i] && input[i] <= '9')) {
                if (isNum) {
                    isNum = false;
                    nums.push_back(num);
                    num = 0;
                }
                if (i < (int)input.size()) {
                    ops.push_back(input[i]);
                }
            } else {
                isNum = true;
                num = num * 10 + input[i] - '0';
            }
        }
        int n = (int)nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i + j < n; ++i) {
                if (j == 0) {
                    dp[i][i].push_back(nums[i]);
                } else if (j == 1) {
                    dp[i][i + j].push_back(calc(nums[i], ops[i], nums[i + 1]));
                } else {
                    for (int k = 0; k < j; ++k) {
                        for (auto v1 : dp[i][i + k]) {
                            for (auto v2 : dp[i + k + 1][i + j]) {
                                dp[i][i + j].push_back(calc(v1, ops[i + k], v2));
                            }
                        }
                    }
                }
            }
        }
        sort(dp[0][n - 1].begin(), dp[0][n - 1].end());
        return dp[0][n - 1];
    }
private:
    int calc(int x, char op, int y) {
        switch (op) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
        }
        return 0;
    }
};
