#include <vector>
#include <algorithm>
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderButtom(TreeNode *root) {
        vector<vector<int>> ret;
        dfs(root, ret, 0);
        for (int i = 0; i < (ret.size() >> 1); ++i) {
            swap(ret[i], ret[ret.size() - i - 1]);
        }
        return ret;
    }
private:
    void dfs(TreeNode *node, vector<vector<int>> &ret, int depth) {
        if (node == NULL) {
            return;
        }
        if (depth >= ret.size()) {
            ret.push_back(vector<int>());
        }
        ret[depth].push_back(node->val);
        dfs(node->left, ret, depth + 1);
        dfs(node->right, ret, depth + 1);
    }
};
