class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        static int DIR_X[] = {0, 0, -1, 1};
        static int DIR_Y[] = {1, -1, 0, 0};
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        vector<vector<int>> len(n, vector<int>(m, 1));
        vector<vector<bool>> visit(n, vector<bool>(m, true));
        queue<pair<int, int>> pos;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pos.push({i, j});
            }
        }
        while (!pos.empty()) {
            auto front = pos.front();
            pos.pop();
            int x = front.first;
            int y = front.second;
            for (int k = 0; k < 4; ++k) {
                int tx = x + DIR_X[k];
                int ty = y + DIR_Y[k];
                if (0 <= tx && tx < n) {
                    if (0 <= ty && ty < m) {
                        if (matrix[tx][ty] > matrix[x][y]) {
                            if (len[tx][ty] < len[x][y] + 1) {
                                len[tx][ty] = len[x][y] + 1;
                                if (!visit[tx][ty]) {
                                    visit[tx][ty] = true;
                                    pos.push({tx, ty});
                                }
                            }
                        }
                    }
                }
            }
            visit[x][y] = false;
        }
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLen = max(maxLen, len[i][j]);
            }
        }
        return maxLen;
    }
};
