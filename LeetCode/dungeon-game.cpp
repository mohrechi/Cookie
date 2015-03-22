class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int height = dungeon.size();
        int width = dungeon[0].size();
        vector<vector<int>> dp(height, vector<int>(width));
        dp[height-1][width-1] = dungeon[height-1][width-1] < 0 ? -dungeon[height-1][width-1] + 1 : 1;
        for (int i = height-2; i >= 0; --i) {
            dp[i][width-1] = max(1, dp[i+1][width-1] - dungeon[i][width-1]);
        }
        for (int j = width-2; j >= 0; --j) {
            dp[height-1][j] = max(1, dp[height-1][j+1] - dungeon[height-1][j]);
        }
        for (int i = height-2; i >= 0; --i) {
            for (int j = width-2; j >= 0; --j) {
                dp[i][j] = min(max(1, dp[i+1][j] - dungeon[i][j]),
                               max(1, dp[i][j+1] - dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};
