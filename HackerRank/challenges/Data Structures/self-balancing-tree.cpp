inline int getHeight(node* root) {
    if (root == nullptr) {
        return -1;
    }
    return root->ht;
}

inline void updateHeight(node* root) {
    if (root != nullptr) {
        root->ht = max(getHeight(root->left), getHeight(root->right)) + 1;
    }
}

inline int getDiff(node* root) {
    if (root == nullptr) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

inline node* rotateLeft(node* parent, node* curr) {
    parent->right = curr->left;
    curr->left = parent;
    updateHeight(parent);
    updateHeight(curr);
    return curr;
}

inline node* rotateRight(node* parent, node* curr) {
    parent->left = curr->right;
    curr->right = parent;
    updateHeight(parent);
    updateHeight(curr);
    return curr;
}

node* insert(node* root, int val) {
    if (root == nullptr) {
        node* newNode = new node();
        newNode->val = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        updateHeight(newNode);
        return newNode;
    }
    if (val <= root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    updateHeight(root);
    int diff = getDiff(root);
    if (diff > 1) {
        if (root->left->left == nullptr) {
            root->left = rotateLeft(root->left, root->left->right);
        }
        return rotateRight(root, root->left);
    }
    if (diff < -1) {
        if (root->right->right == nullptr) {
            root->right = rotateRight(root->right, root->right->left);
        }
        return rotateLeft(root, root->right);
    }
    return root;
}