void Inorder(node *root) {
    if (root == nullptr) {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}