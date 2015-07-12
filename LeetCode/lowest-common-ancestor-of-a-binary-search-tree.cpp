class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or p == nullptr or q == nullptr) {
            return nullptr;
        }
        if (p->val > q->val) {
            swap(p, q);
        }
        while (root != nullptr) {
            if (p->val <= root->val and root->val <= q->val) {
                return root;
            }
            if (q->val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return nullptr;
    }
};
