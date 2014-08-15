class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        this->n = n;
        vector<vector<int>> valid(n, vector<int>(n, 0));
        vector<string> board(n, string(n, '.'));
        ans.clear();
        dfs(0, board, valid);
        return ans;
    }
private:
    int n;
    vector<vector<string>> ans;
    void dfs(int row, vector<string> &board, vector<vector<int>> &valid) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
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
                board[row][k] = 'Q';
                dfs(row + 1, board, valid);
                board[row][k] = '.';
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
    }
};
