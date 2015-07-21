class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or p == nullptr or q == nullptr) {
            return nullptr;
        }
        if (p == root or q == root) {
            return root;
        }
        TreeNode* comL = lowestCommonAncestor(root->left, p, q);
        TreeNode* comR = lowestCommonAncestor(root->right, p, q);
        if (comL != nullptr and comR != nullptr) {
            return root;
        }
        if (comL != nullptr) {
            return comL;
        }
        if (comR != nullptr) {
            return comR;
        }
        return nullptr;
    }
};
