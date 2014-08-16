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
    void recoverTree(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *node = nullptr;
        int prev = -0x7fffffff;
        TreeNode *node1 = find1(root, prev, node);
        node = nullptr;
        prev = 0x7fffffff;
        TreeNode *node2 = find2(root, prev, node);
        swap(node1->val, node2->val);

    }
private:
    TreeNode *find1(TreeNode *node, int &prevVal, TreeNode* &prev) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode *ret = find1(node->left, prevVal, prev);
        if (ret != nullptr) {
            return ret;
        }
        if (prevVal > node->val) {
            return prev;
        }
        prev = node;
        prevVal = node->val;
        return find1(node->right, prevVal, prev);
    }
    TreeNode *find2(TreeNode *node, int &prevVal, TreeNode* &prev) {
        if (node == nullptr) {
            return nullptr;
        }
        TreeNode *ret = find2(node->right, prevVal, prev);
        if (ret != nullptr) {
            return ret;
        }
        if (prevVal < node->val) {
            return prev;
        }
        prev = node;
        prevVal = node->val;
        return find2(node->left, prevVal, prev);
    }
};
