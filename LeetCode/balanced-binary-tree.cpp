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
    bool isBalanced(TreeNode *root) {
        return getDepth(root) != -1;
    }
private:
    int getDepth(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int l = getDepth(node->left);
        int r = getDepth(node->right);
        if (l == -1 || r == -1) {
            return -1;
        }
        if (abs(l - r) > 1) {
            return -1;
        }
        return max(l, r) + 1;
    }
};
