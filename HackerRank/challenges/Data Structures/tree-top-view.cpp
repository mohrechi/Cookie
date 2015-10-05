void print_left(node *root) {
    if (root == nullptr) {
        return;
    }
    print_left(root->left);
    cout << root->data << " ";
}

void print_right(node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    print_right(root->right);
}

void top_view(node *root) {
    if (root == nullptr) {
        return;
    }
    print_left(root);
    print_right(root->right);
}