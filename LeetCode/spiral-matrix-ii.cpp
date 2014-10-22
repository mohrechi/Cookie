const int DIRX[] = {0, 1, 0, -1};
const int DIRY[] = {1, 0, -1, 0};

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int x = 0, y = 0, dir = 0, index = 0;
        while (index < n * n) {
            if (ret[x][y] == 0) {
                ret[x][y] = ++index;
            }
            int tx = x + DIRX[dir];
            int ty = y + DIRY[dir];
            if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
                if (ret[tx][ty] == 0) {
                    x = tx;
                    y = ty;
                } else {
                    dir = (dir + 1) % 4;
                }
            } else {
                dir = (dir + 1) % 4;
            }
        }
        return ret;
    }
};
