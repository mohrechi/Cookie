node* lca(node* root, int v1, int v2) {
    if (v1 > v2) {
        swap(v1, v2);
    }
    while (true) {
        if (v2 < root->data) {
            root = root->left;
        } else if (v1 > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}