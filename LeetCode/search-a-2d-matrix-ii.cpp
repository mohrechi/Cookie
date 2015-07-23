class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = (int)matrix.size();
        if (n == 0) {
            return false;
        }
        int m = (int)matrix[0].size();
        if (m == 0) {
            return false;
        }
        int tx = 0, ty = m - 1;
        while (tx < n && ty >= 0) {
            if (matrix[tx][ty] == target) {
                return true;
            }
            if (matrix[tx][ty] < target) {
                ++tx;
            } else {
                --ty;
            }
        }
        return false;
    }
};
