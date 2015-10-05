#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

class Splay {
public:
    void build(int a[], int n) {
        root = build(a, 0, n + 2, nullptr);
    }
    void moveToFront(int l, int r) {
        splay(find(l), nullptr);
        splay(find(r + 2), root);
        Node* interval = root->right->left;
        root->right->left = nullptr;
        update(root->right);
        update(root);
        splay(find(1), nullptr);
        splay(find(2), root);
        root->right->left = interval;
        interval->parent = root->right;
        update(root->right);
        update(root);
    }
    void moveToEnd(int l, int r) {
        splay(find(l), nullptr);
        splay(find(r + 2), root);
        Node* interval = root->right->left;
        root->right->left = nullptr;
        update(root->right);
        update(root);
        splay(find(root->size - 1), nullptr);
        splay(find(root->size), root);
        root->right->left = interval;
        interval->parent = root->right;
        update(root->right);
        update(root);
    }
    void traverse(int a[]) {
        idx = 0;
        traverse(a, root);
    }
    void print() {
        print(root);
    }
private:
    struct Node {
        int val, size;
        Node* parent, *left, *right;
    };
    Node* root = {nullptr};
    int idx;

    inline int getSize(Node* node) {
        return node == nullptr ? 0 : node->size;
    }

    inline void update(Node* node) {
        if (node != nullptr) {
            node->size = 1 + getSize(node->left) + getSize(node->right);
        }
    }

    Node* build(int a[], int l, int r, Node* parent) {
        if (l >= r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        Node* node = new Node();
        node->val = a[mid];
        node->parent = parent;
        node->left = build(a, l, mid, node);
        node->right = build(a, mid + 1, r, node);
        update(node);
        return node;
    }

    Node* find(int k) {
        Node* node = root;
        while (k != getSize(node->left) + 1) {
            if (k <= getSize(node->left)) {
                node = node->left;
            } else {
                k -= getSize(node->left) + 1;
                node = node->right;
            }
        }
        return node;
    }

    void rotateLeft(Node* x) {
        Node* p = x->parent;
        p->right = x->left;
        if (p->right != nullptr) {
            p->right->parent = p;
        }
        x->left = p;
        x->parent = p->parent;
        if (p->parent != nullptr) {
            if (p->parent->left == p) {
                p->parent->left = x;
            } else {
                p->parent->right = x;
            }
        }
        p->parent = x;
        update(p);
        update(x);
        if (root == p) {
            root = x;
        }
    }

    void rotateRight(Node* x) {
        Node* p = x->parent;
        p->left = x->right;
        if (p->left != nullptr) {
            p->left->parent = p;
        }
        x->right = p;
        x->parent = p->parent;
        if (p->parent != nullptr) {
            if (p->parent->left == p) {
                p->parent->left = x;
            } else {
                p->parent->right = x;
            }
        }
        p->parent = x;
        update(p);
        update(x);
        if (root == p) {
            root = x;
        }
    }

    void splay(Node* x, Node* y) {
        while (x->parent != y) {
            if (x->parent->parent == y) {
                if (x->parent->left == x) {
                    rotateRight(x);
                } else {
                    rotateLeft(x);
                }
            } else if (x->parent->parent->left == x->parent) {
                if (x->parent->left == x) {
                    rotateRight(x->parent);
                    rotateRight(x);
                } else {
                    rotateLeft(x);
                    rotateRight(x);
                }
            } else {
                if (x->parent->right == x) {
                    rotateLeft(x->parent);
                    rotateLeft(x);
                } else {
                    rotateRight(x);
                    rotateLeft(x);
                }
            }
        }
        update(x);
    }

    void traverse(int a[], Node* node) {
        if (node == nullptr) {
            return;
        }
        traverse(a, node->left);
        a[idx++] = node->val;
        traverse(a, node->right);
    }

    void print(Node* node, int space = 0) {
        if (node == nullptr) {
            return;
        }
        print(node->right, space + 2);
        for (int i = 0; i < space; ++i) {
            putchar(' ');
        }
        if (node->parent == nullptr) {
            printf("(%d, %d)\n", node->val, node->size);
        } else {
            printf("(%d, %d, %d)\n", node->val, node->size, node->parent->val);
        }
        print(node->left, space + 2);
        if (space == 0) {
            putchar('\n');
        }
    }
} splay;

int n, a[MAXN];

int main() {
    int m, o, i, j;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    splay.build(a, n);
    while (m--) {
        scanf("%d%d%d", &o, &i, &j);
        o == 1 ? splay.moveToFront(i, j) : splay.moveToEnd(i, j);
    }
    splay.traverse(a);
    printf("%d\n", abs(a[1] - a[n]));
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            putchar(' ');
        }
        printf("%d", a[i]);
    }
    putchar('\n');
    return 0;
}
