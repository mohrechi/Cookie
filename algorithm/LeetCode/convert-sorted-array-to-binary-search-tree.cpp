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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return build(num, 0, num.size());
    }
private:
    TreeNode *build(vector<int> &num, int left, int right) {
        if (left >= right) {
            return NULL;
        }
        int mid = (left + right) >> 1;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = build(num, left, mid);
        node->right = build(num, mid + 1, right);
    }
};
