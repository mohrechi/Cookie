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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
private:
    bool isValidBST(TreeNode *node, int left, int right) {
        if (node == nullptr) {
            return true;
        }
        return left < node->val && node->val < right &&
               isValidBST(node->left, left, node->val) &&
               isValidBST(node->right, node->val, right);
    }
};
