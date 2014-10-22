class Solution {
public:
    int totalNQueens(int n) {
        this->n = n;
        vector<vector<int>> valid(n, vector<int>(n, 0));
        return dfs(0, valid);
    }
private:
    int n;
    int dfs(int row, vector<vector<int>> &valid) {
        if (row == n) {
            return 1;
        }
        int sum = 0;
        for (int k = 0; k < n; ++k) {
            if (valid[row][k] == 0) {
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i || j) {
                            int tx = row + i;
                            int ty = k + j;
                            while (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                                ++valid[tx][ty];
                                tx += i;
                                ty += j;
                            }
                        }
                    }
                }
                sum += dfs(row + 1, valid);
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        if (i || j) {
                            int tx = row + i;
                            int ty = k + j;
                            while (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                                --valid[tx][ty];
                                tx += i;
                                ty += j;
                            }
                        }
                    }
                }
            }
        }
        return sum;
    }
};
