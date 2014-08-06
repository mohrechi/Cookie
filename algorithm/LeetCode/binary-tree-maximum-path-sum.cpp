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
    int maxPathSum(TreeNode *root) {
        return dfs(root).maxSum;
    }
private:
    struct Node {
        int maxSum;
        int maxLinkSum;
    };
    Node dfs(TreeNode *node) {
        if (node == NULL) {
            return {0, 0};
        }
        Node l = dfs(node->left);
        Node r = dfs(node->right);
        Node ret;
        ret.maxLinkSum = max(node->val, node->val + max(l.maxLinkSum, r.maxLinkSum));
        ret.maxSum = -0x3f3f3f3f;
        if (node->left != NULL) {
            ret.maxSum = max(ret.maxSum, l.maxSum);
        }
        if (node->right != NULL) {
            ret.maxSum = max(ret.maxSum, r.maxSum);
        }
        ret.maxSum = max(ret.maxSum, ret.maxLinkSum);
        ret.maxSum = max(ret.maxSum, node->val + l.maxLinkSum + r.maxLinkSum);
        return ret;
    }
};
