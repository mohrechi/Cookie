class Solution {
public:
    vector<string> addOperators(string num, int target) {
        ans.clear();
        if (num.size() == 0) {
            return ans;
        }
        this->num = num;
        this->target = target;
        dfs("", 0, 0, 0);
        return ans;
    }
private:
    vector<string> ans;
    string num;
    int target;
    
    void dfs(string expr, long long pos, long long eval, long long mul) {
        if (pos == (int)num.size()) {
            if (eval == target) {
                ans.push_back(expr);
            }
            return;
        }
        long long acc = 0;
        string sub;
        for (int i = pos; i < (int)num.size(); ++i) {
            if (i > pos && acc == 0) {
                break;
            }
            sub += num[i];
            acc = acc * 10 + num[i] - '0';
            if (pos == 0) {
                dfs(expr + sub, i + 1, acc, acc);
            } else {
                dfs(expr + "+" + sub, i + 1, eval + acc, acc);
                dfs(expr + "-" + sub, i + 1, eval - acc, -acc);
                dfs(expr + "*" + sub, i + 1, eval - mul + mul * acc, mul * acc);
            }
        }
    }
};
