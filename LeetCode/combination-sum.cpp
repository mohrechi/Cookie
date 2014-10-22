class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> path;
        com.clear();
        sort(candidates.begin(), candidates.end());
        dfs(0, target, 0, path, candidates);
        return com;
    }
private:
    vector<vector<int>> com;
    void dfs(int sum, int target, int index, vector<int> &path, vector<int> &can) {
        if (sum == target) {
            com.push_back(path);
            return;
        }
        if (index == can.size()) {
            return;
        }
        if (index > 0) {
            while (can[index] == can[index - 1]) {
                ++index;
            }
        }
        for (int i = 0; sum + i <= target; i += can[index]) {
            dfs(sum + i, target, index + 1, path, can);
            path.push_back(can[index]);
        }
        while (path.size() > 0) {
            if (*path.rbegin() == can[index]) {
                path.pop_back();
            } else {
                break;
            }
        }
    }
};
