class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        vector<vector<int> > temp;
        for (int i = 0; i < n; ++i) {
            temp.push_back(vector<int>());
            for (int j = 0; j < n; ++j) {
                temp[i].push_back(matrix[n - j - 1][i]);
            }
        }
        matrix = temp;
    }
};
