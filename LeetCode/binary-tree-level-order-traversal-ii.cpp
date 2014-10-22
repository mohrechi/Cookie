/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        dfs(root, ret, 0);
        for (int i = 0; i < (ret.size() >> 1); ++i) {
            swap(ret[i], ret[ret.size() - i - 1]);
        }
        return ret;
    }
private:
    void dfs(TreeNode *node, vector<vector<int>> &ret, int depth) {
        if (node == NULL) {
            return;
        }
        if (depth >= ret.size()) {
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(node->val);
        dfs(node->left, ret, depth + 1);
        dfs(node->right, ret, depth + 1);
    }
};
