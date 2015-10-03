#include <bits/stdc++.h>
using namespace std;

class Splay {
public:
    Splay() {
        add(-10000000000LL);
        add( 10000000000LL);
    }

    void add(long long x) {
        if (root == nullptr) {
            root = add(nullptr, nullptr, x);
        } else {
            add(root, nullptr, x);
        }
    }

    void add(int x) {
        add((long long)x);
        splay(findK(getK(x)), nullptr);
        median();
    }

    void remove(int x) {
        int k = getK(x);
        if (k == -1) {
            puts("Wrong!");
            return;
        }
        splay(findK(k - 1), nullptr);
        splay(findK(k + 1), root);
        delete root->right->left;
        root->right->left = nullptr;
        update(root->right);
        update(root);
        median();
    }

    void median() {
        int n = root->size;
        if (n == 2) {
            puts("Wrong!");
            return;
        }
        splay(findK((n >> 1) + 1), nullptr);
        long long val = root->val;
        if (n & 1) {
            printf("%d\n", (int)val);
        } else {
            splay(findK(n >> 1), nullptr);
            val += root->val;
            if (val & 1) {
                printf("%.1f\n", val * 0.5);
            } else {
                printf("%d\n", (int)(val >> 1));
            }
        }
    }

    void print() {
        print(root);
    }
private:
    struct Node {
        int size;
        long long val;
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

    Node* add(Node* node, Node* parent, long long val) {
        if (node == nullptr) {
            Node* node = new Node();
            node->val = val;
            node->size = 1;
            node->parent = parent;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
        if (val <= node->val) {
            node->left = add(node->left, node, val);
        } else {
            node->right = add(node->right, node, val);
        }
        update(node);
        return node;
    }

    Node* findK(int k) {
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

    int getK(int val) {
        int k = 0;
        Node* node = root;
        while (true) {
            if (node == nullptr) {
                return -1;
            }
            if (val >= node->val) {
                k += getSize(node->left) + 1;
            }
            if (node->val == val) {
                break;
            }
            if (val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return k;
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

    void print(Node* node, int space = 0) {
        if (node == nullptr) {
            return;
        }
        print(node->right, space + 4);
        for (int i = 0; i < space; ++i) {
            putchar(' ');
        }
        printf("%I64d\n", node->val);
        print(node->left, space + 4);
        if (space == 0) {
            putchar('\n');
        }
    }
} splay;

int main() {
    int n, x;
    char op[2];
    scanf("%d", &n);
    while (n--) {
        scanf("%s%d", op, &x);
        (*op == 'a') ? splay.add(x) : splay.remove(x);
    }
    return 0;
}
