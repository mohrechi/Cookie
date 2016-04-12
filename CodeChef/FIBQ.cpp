#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;

struct Matrix {
    long long data[2][2];
};

Matrix operator +(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
            if (c.data[i][j] >= MOD) {
                c.data[i][j] -= MOD;
            }
        }
    }
    return c;
}

Matrix operator *(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.data[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                c.data[i][j] += a.data[i][k] * b.data[k][j] % MOD;
                if (c.data[i][j] >= MOD) {
                    c.data[i][j] -= MOD;
                }
            }
        }
    }
    return c;
}

Matrix fibonacci(int n) {
    Matrix trans;
    trans.data[0][0] = 1, trans.data[0][1] = 1;
    trans.data[1][0] = 1, trans.data[1][1] = 0;
    Matrix m;
    m.data[0][0] = 1, m.data[0][1] = 0;
    m.data[1][0] = 0, m.data[1][1] = 1;
    for (int i = 0; (1 << i) <= n; ++i) {
        if (n & (1 << i)) {
            m = m * trans;
        }
        trans = trans * trans;
    }
    return m;
}

int n, m;
int a[MAXN];

struct TreeNode {
    int l, r;
    Matrix m;
} tree[MAXN * 4];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void pushUp(int x) {
    Matrix& l = tree[lc(x)].m;
    Matrix& r = tree[rc(x)].m;
    tree[x].m = l + r + l * r;
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].m = fibonacci(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void update(int x, int pos, int val) {
    if (tree[x].l == tree[x].r) {
        tree[x].m = fibonacci(val);
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid) {
        update(lc(x), pos, val);
    } else {
        update(rc(x), pos, val);
    }
    pushUp(x);
}

Matrix query(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].m;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    Matrix lv = query(lc(x), l, mid);
    Matrix rv = query(rc(x), mid + 1, r);
    return lv + rv + lv * rv;
}

int main() {
    int x, y;
    char op[2];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (m--) {
        scanf("%s%d%d", op, &x, &y);
        if (op[0] == 'C') {
            update(1, x, y);
        } else {
            printf("%d\n", (int)query(1, x, y).data[1][0]);
        }
    }
    return 0;
}
