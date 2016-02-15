class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = n > 0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sums[i + 1][j + 1] = sums[i + 1][j] + matrix[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sums[i][j] += sums[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
private:
    vector<vector<int>> sums;
};
