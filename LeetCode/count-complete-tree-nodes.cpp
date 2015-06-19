class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int d = getDepth(root);
        int len = 1 << (d - 1);
        int l = 0, r = len - 1;
        int num = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (getDepth(root, mid, d - 2) == d) {
                l = mid + 1;
                num = max(num, mid);
            } else {
                r = mid - 1;
            }
        }
        return len + num;
    }

    int getDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + getDepth(root->left);
    }

    int getDepth(TreeNode* root, int num, int idx) {
        if (root == nullptr) {
            return 0;
        }
        if (num & (1 << idx)) {
            return 1 + getDepth(root->right, num, idx - 1);
        }
        return 1 + getDepth(root->left, num, idx - 1);
    }
};
