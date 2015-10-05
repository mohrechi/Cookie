int height(node * root) {
    return root == nullptr ? 0 : max(height(root->left), height(root->right)) + 1;
}