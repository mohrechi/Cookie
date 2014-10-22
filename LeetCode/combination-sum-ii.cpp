class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<int> path;
        com.clear();
        sort(num.begin(), num.end());
        dfs(0, target, 0, path, num, false);
        return com;
    }
private:
    vector<vector<int>> com;
    void dfs(int sum, int target, int index, vector<int> &path, vector<int> &num, bool take) {
        if (sum == target) {
            com.push_back(path);
            return;
        }
        if (index == num.size()) {
            return;
        }
        dfs(sum, target, index + 1, path, num, false);
        if (index > 0) {
            if (num[index] == num[index - 1]) {
                if (!take) {
                    return;
                }
            }
        }
        if (sum + num[index] <= target) {
            path.push_back(num[index]);
            dfs(sum + num[index], target, index + 1, path, num, true);
            path.pop_back();
        }
    }
};
