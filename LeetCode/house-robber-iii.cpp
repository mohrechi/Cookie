class Solution {
public:
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
private:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int first = max(left.first, left.second) + max(right.first, right.second);
        int second = root->val + left.first + right.first;
        return {first, second};
    }
};
