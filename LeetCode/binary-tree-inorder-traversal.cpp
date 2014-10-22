/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
private:
    void dfs(TreeNode *node, vector<int> &ret) {
        if (node == NULL) {
            return;
        }
        dfs(node->left, ret);
        ret.push_back(node->val);
        dfs(node->right, ret);
    }
};
