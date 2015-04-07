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
    vector<int> rightSideView(TreeNode *root) {
        right.clear();
        search(root, 0, 1);
        return right;
    }
private:
    vector<int> pos;
    vector<int> right;
    
    void search(TreeNode *node, int depth, int p) {
        if (node == nullptr) {
            return;
        }
        if (depth >= right.size()) {
            pos.push_back(p);
            right.push_back(node->val);
        } else if (p > pos[depth]) {
            pos[depth] = p;
            right[depth] = node->val;
        }
        search(node->left, depth + 1, p << 1);
        search(node->right, depth + 1, (p << 1) + 1);
    }
};