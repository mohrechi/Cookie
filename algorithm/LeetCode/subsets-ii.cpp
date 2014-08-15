class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        ans.clear();
        vector<int> path;
        dfs(S, 0, path, false);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &S, int index, vector<int> &path, bool take) {
        if (index == S.size()) {
            ans.push_back(path);
            return;
        }
        dfs(S, index + 1, path, false);
        if (index > 0) {
            if (S[index] == S[index - 1]) {
                if (!take) {
                    return;
                }
            }
        }
        path.push_back(S[index]);
        dfs(S, index + 1, path, true);
        path.pop_back();
    }
};
