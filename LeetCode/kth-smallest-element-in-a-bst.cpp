class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cnt = new TreeNode(0);
        createCnt(root, cnt);
        return find(root, cnt, k);
    }
private:
    void createCnt(TreeNode* root, TreeNode* cnt) {
        cnt->val = 1;
        if (root->left != nullptr) {
            cnt->left = new TreeNode(0);
            createCnt(root->left, cnt->left);
            cnt->val += cnt->left->val;
        }
        if (root->right != nullptr) {
            cnt->right = new TreeNode(0);
            createCnt(root->right, cnt->right);
            cnt->val += cnt->right->val;
        }
    }
    int find(TreeNode* root, TreeNode* cnt, int k) {
        int leftNum = cnt->left == nullptr ? 0 : cnt->left->val;
        if (leftNum + 1 == k) {
            return root->val;
        }
        if (k <= leftNum) {
            return find(root->left, cnt->left, k);
        }
        return find(root->right, cnt->right, k - leftNum - 1);
    }
};
