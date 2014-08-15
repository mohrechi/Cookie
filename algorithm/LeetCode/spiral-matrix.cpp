const int DIRX[] = {0, 1, 0, -1};
const int DIRY[] = {1, 0, -1, 0};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if (matrix.size() > 0) {
            if (matrix[0].size() > 0) {
                int dir = 0;
                int x = 0, y = 0;
                int n = matrix.size();
                int m = matrix[0].size();
                vector<vector<bool>> visit(n, vector<bool>(m, false));
                while (ret.size() < n * m) {
                    if (!visit[x][y]) {
                        visit[x][y] = true;
                        ret.push_back(matrix[x][y]);
                    }
                    int tx = x + DIRX[dir];
                    int ty = y + DIRY[dir];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                        if (!visit[tx][ty]) {
                            x = tx;
                            y = ty;
                        } else {
                            dir = (dir + 1) % 4;
                        }
                    } else {
                        dir = (dir + 1) % 4;
                    }
                }
            }
        }
        return ret;
    }
};
