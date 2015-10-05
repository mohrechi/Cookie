class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        static int DIR_X[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        static int DIR_Y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + DIR_X[k];
                    int y = j + DIR_Y[k];
                    if (0 <= x && x < n) {
                        if (0 <= y && y < m) {
                            if (board[x][y] & 1) {
                                ++cnt;
                            }
                        }
                    }
                }
                if (board[i][j] & 1) {
                    if (cnt == 2 || cnt == 3) {
                        board[i][j] |= 2;
                    }
                } else {
                    if (cnt == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
