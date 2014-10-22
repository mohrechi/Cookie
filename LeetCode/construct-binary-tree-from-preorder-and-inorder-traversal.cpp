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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode *build(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl >= pr) {
            return NULL;
        }
        for (int i = il; i < ir; ++i) {
            if (inorder[i] == preorder[pl]) {
                TreeNode *node = new TreeNode(preorder[pl]);
                node->left = build(preorder, pl + 1, pl + 1 + i - il, inorder, il, i);
                node->right = build(preorder, pl + 1 + i - il, pr, inorder, i + 1, ir);
                return node;
            }
        }
    }
};
