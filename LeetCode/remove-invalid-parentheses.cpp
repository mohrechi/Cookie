class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        len = 0;
        valids.clear();
        string path = "";
        removeDfs(s, path, 0, 0);
        return vector<string>(valids.begin(), valids.end());
    }
private:
    int len;
    unordered_set<string> valids;
    void removeDfs(const string& s, string& path, int idx, int num) {
        if (idx == (int)s.length()) {
            if (num != 0 || (int)path.size() < len) {
                return;
            }
            if ((int)path.size() > len) {
                len = path.size();
                valids.clear();
            }
            valids.insert(path);
            return;
        }
        if (s[idx] == '(') {
            removeDfs(s, path, idx + 1, num);
            path.push_back(s[idx]);
            removeDfs(s, path, idx + 1, num + 1);
            path.pop_back();
        } else if (s[idx] == ')') {
            removeDfs(s, path, idx + 1, num);
            if (num > 0) {
                path.push_back(s[idx]);
                removeDfs(s, path, idx + 1, num - 1);
                path.pop_back();
            }
        } else {
            path.push_back(s[idx]);
            removeDfs(s, path, idx + 1, num);
            path.pop_back();
        }
    }
};
