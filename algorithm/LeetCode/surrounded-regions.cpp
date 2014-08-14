const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        visit.clear();
        h = board.size();
        for (auto b : board) {
            visit.push_back(vector<bool>(b.size(), false));
            w = b.size();
        }
        for (int i = 0; i < h; ++i) {
            dfs(i, 0, board);
            dfs(i, w - 1, board);
        }
        for (int j = 0; j < w; ++j) {
            dfs(0, j, board);
            dfs(h - 1, j, board);
        }
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == 'O' && !visit[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
private:
    int h, w;
    vector<vector<bool>> visit;
    void dfs(int x, int y, vector<vector<char>> &board) {
        if (board[x][y] == 'O') {
            if (!visit[x][y]) {
                visit[x][y] = true;
                for (int k = 0; k < 4; ++k) {
                    int tx = x + DIR_X[k];
                    int ty = y + DIR_Y[k];
                    if (tx >= 0 && tx < h) {
                        if (ty >= 0 && ty < w) {
                            dfs(tx, ty, board);
                        }
                    }
                }
            }
        }
    }
};
