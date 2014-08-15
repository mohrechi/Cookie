class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        ans.clear();
        vector<int> path;
        dfs(S, 0, path);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void dfs(vector<int> &S, int index, vector<int> &path) {
        if (index == S.size()) {
            ans.push_back(path);
            return;
        }
        dfs(S, index + 1, path);
        path.push_back(S[index]);
        dfs(S, index + 1, path);
        path.pop_back();
    }
};
