class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> hdict;
        for (auto word : dict) {
            int hash = 0;
            for (auto c : word) {
                hash = hash * 131 + c;
            }
            hdict.insert(hash);
        }
        vector<int> hashes(s.size(), 0);
        prev.clear();
        for (int i = 0; i <= s.size(); ++i) {
            prev.push_back(vector<int>());
        }
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                hashes[j] = hashes[j] * 131 + s[i - 1];
                if (hdict.find(hashes[j]) != hdict.end()) {
                    prev[i].push_back(j);
                }
            }
        }
        ret.clear();
        vector<string> path;
        dfs(s, s.length(), path);
        return ret;
    }
private:
    vector<string> ret;
    vector<vector<int>> prev;
    void dfs(string &s, int index, vector<string> &path) {
        if (index == 0) {
            string temp;
            for (int i = (int)path.size() - 1; i >= 0; --i) {
                if (i <= (int)path.size() - 2) {
                    temp += " ";
                }
                temp += path[i];
            }
            ret.push_back(temp);
            return;
        }
        string temp;
        for (auto v : prev[index]) {
            path.push_back(s.substr(v, index - v));
            dfs(s, v, path);
            path.pop_back();
        }
    }
};
