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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
private:
    TreeNode *build(vector<int> &postorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl >= pr) {
            return NULL;
        }
        for (int i = il; i < ir; ++i) {
            if (inorder[i] == postorder[pr - 1]) {
                TreeNode *node = new TreeNode(postorder[pr - 1]);
                node->left = build(postorder, pl, pl + i - il, inorder, il, i);
                node->right = build(postorder, pl + i - il, pr - 1, inorder, i + 1, ir);
                return node;
            }
        }
    }
};
