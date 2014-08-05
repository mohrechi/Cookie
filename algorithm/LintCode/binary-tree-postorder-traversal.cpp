#include <vector>
#include "lintcode.h"

using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
private:
    void dfs(TreeNode *node, vector<int> &ret) {
        if (node == NULL) {
            return;
        }
        dfs(node->left, ret);
        dfs(node->right, ret);
        ret.push_back(node->val);
    }
};
