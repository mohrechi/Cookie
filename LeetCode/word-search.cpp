const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) {
            return true;
        }
        vector<vector<bool>> visit;
        for (int i = 0; i < board.size(); ++i) {
            visit.push_back(vector<bool>(board[i].size(), false));
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    visit[i][j] = true;
                    if (dfs(i, j, 1, board, word, visit)) {
                        return true;
                    }
                    visit[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    bool dfs(int x, int y, int index, vector<vector<char>> &board, string &word, vector<vector<bool>> &visit) {
        if (index == word.length()) {
            return true;
        }
        for (int k = 0; k < 4; ++k) {
            int tx = x + DIR_X[k];
            int ty = y + DIR_Y[k];
            if (tx >= 0 && tx < board.size()) {
                if (ty >= 0 && ty < board[tx].size()) {
                    if (board[tx][ty] == word[index]) {
                        if (!visit[tx][ty]) {
                            visit[tx][ty] = true;
                            if (dfs(tx, ty, index + 1, board, word, visit)) {
                                return true;
                            }
                            visit[tx][ty] = false;
                        }
                    }
                }
            }
        }
        return false;
    }
};
