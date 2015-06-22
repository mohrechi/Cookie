var combinationSum3 = function(k, n) {
    var ans = [];
    var path = [];
    function dfs(sum, idx, num) {
        if (num == k) {
            if (sum == n) {
                ans.push(path.slice());
            }
        } else {
            for (var i = idx; i <= 9; ++i) {
                if (sum + i > n) {
                    break;
                }
                path.push(i)
                dfs(sum + i, i + 1, num + 1);
                path.pop();
            }
        }
    }
    dfs(0, 1, 0, []);
    return ans;
};
