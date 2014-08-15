class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        if (matrix[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int j = 0; j < matrix[0].size(); ++j) {
            heights[0][j] = matrix[0][j] == '1';
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            ans = max(ans, largestRectangleArea(heights[i]));
        }
        return ans;
    }
private:
    int largestRectangleArea(vector<int> &height) {
        int ans = 0;
        height.push_back(0);
        stack<int> s;
        stack<int> p;
        s.push(height[0]);
        p.push(0);
        for (int i = 1; i < height.size(); ++i) {
            int index = i;
            if (height[i] < s.top()) {
                while (!s.empty()) {
                    if (s.top() > height[i]) {
                        ans = max(ans, (i - p.top()) * s.top());
                        s.pop();
                        index = p.top();
                        p.pop();
                    } else {
                        break;
                    }
                }
            }
            s.push(height[i]);
            p.push(index);
        }
        return ans;
    }
};
