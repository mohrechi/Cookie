/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        it = root;
        height = 0;
        if (it != NULL) {
            add(height++, it);
            while (it->left != NULL) {
                it = it->left;
                add(height++, it);
            }
        }
        findNext = true;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (it == NULL) {
            return false;
        }
        if (findNext) {
            return true;
        }
        gotoNext();
        findNext = true;
        return it != NULL;
    }

    /** @return the next smallest number */
    int next() {
        if (findNext) {
            findNext = false;
        } else {
            gotoNext();
        }
        return it->val;
    }
private:
    TreeNode* it;
    bool findNext;
    int height;
    vector<TreeNode*> head;

    void add(int height, TreeNode* value) {
        if (height >= head.size()) {
            head.push_back(value);
        } else {
            head[height] = value;
        }
    }

    void gotoNext() {
        if (it == NULL) {
            return;
        }
        if (it->right != NULL) {
            it = it->right;
            add(height++, it);
            while (it->left != NULL) {
                it = it->left;
                add(height++, it);
            }
            return;
        }
        bool finish = true;
        for (int i = height - 2; i >= 0; --i) {
            if (head[i]->left == it) {
                it = head[i];
                --height;
                finish = false;
                break;
            }
            it = head[i];
            --height;
        }
        if (finish) {
            it = NULL;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */