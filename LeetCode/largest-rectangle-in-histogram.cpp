class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int ans = 0;
        if (height.size() > 0) {
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
        }
        return ans;
    }
};
