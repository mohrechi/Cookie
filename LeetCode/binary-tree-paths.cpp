class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        paths.clear();
        if (root != nullptr) {
            dfs(root, "", true);
        }
        return paths;
    }
private:
    vector<string> paths;
    void dfs(TreeNode *node, string path, bool first = false) {
        if (node == nullptr) {
            return;
        }
        if (!first) {
            path += "->";
        }
        path += int2str(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
            return;
        }
        dfs(node->left, path);
        dfs(node->right, path);
    }
    string int2str(int val) {
        stringstream ss;
        ss << val;
        return ss.str();
    }
};
