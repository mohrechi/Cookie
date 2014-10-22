class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        vector<bool> visit;
        for (int i = 0; i < num.size(); ++i) {
            visit.push_back(false);
        }
        vector<int> path;
        sort(num.begin(), num.end());
        dfs(num, visit, path, result);
        return result;
    }
private:
    void dfs(vector<int> &num, vector<bool> &visit, vector<int> &path, vector<vector<int> > &result) {
        if (path.size() == num.size()) {
            result.push_back(path);
            return;
        }
        int last = -1;
        for (int i = 0; i < num.size(); ++i) {
            if (!visit[i]) {
                if (last != -1) {
                    if (num[last] == num[i]) {
                        continue;
                    }
                }
                visit[i] = true;
                path.push_back(num[i]);
                last = i;
                dfs(num, visit, path, result);
                path.pop_back();
                visit[i] = false;
            }
        }
    }
};
