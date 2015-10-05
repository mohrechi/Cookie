void decode_huff(node* root, string s) {
    node* p = root;
    for (auto c : s) {
        if (c == '0') {
            p = p->left;
        } else {
            p = p->right;
        }
        if (p->left == nullptr && p->right == nullptr) {
            cout << p->data;
            p = root;
        }
    }
    cout << endl;
}