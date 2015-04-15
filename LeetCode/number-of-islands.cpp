class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++num;
                    remove(grid, i, j);
                }
            }
        }
        return num;
    }
private:
    void remove(vector<vector<char>> &grid, int x, int y) {
        grid[x][y] = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) + abs(j) == 1) {
                    int tx = x + i;
                    int ty = y + j;
                    if (0 <= tx && tx < grid.size()) {
                        if (0 <= ty && ty < grid[tx].size()) {
                            if (grid[tx][ty] == '1') {
                                remove(grid, tx, ty);
                            }
                        }
                    }
                }
            }
        }
    }
};