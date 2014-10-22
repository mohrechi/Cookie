class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> index;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                index.push_back(i);
            } else {
                if (index.size() > 0) {
                    if (s[index[index.size() - 1]] == '(') {
                        index.pop_back();
                    } else {
                        index.push_back(i);
                    }
                } else {
                    index.push_back(i);
                }
            }
        }
        int last = 0;
        for (int i = 0; i < index.size(); ++i) {
            ans = max(ans, index[i] - last);
            last = index[i] + 1;
        }
        ans = max(ans, (int)s.length() - last);
        return ans;
    }
};
