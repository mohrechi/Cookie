#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int h, m, n;
int treeNum, treeIdx[MAXN];
int posIdx[MAXN];

class SegmentTree {
public:
    SegmentTree(vector<int>& members) {
        n = members.size() - 1;
        dummy = 0;
        nodes = vector<TreeNode>((n + 5) * 4);
        this->members = members;
        build(1, 1, n);
    }

    inline int add(int pos) {
        if (query(1, pos, n) == 0) {
            dummy += n - pos + 1;
            pos = 1;
        }
        int k = pos == 1 ? 1 : (query(1, 1, pos - 1) + 1);
        int firstEmpty = find(1, k);
        update(1, firstEmpty, -1);
        dummy += firstEmpty - pos;
        return firstEmpty;
    }

    inline void remove(int pos) {
        update(1, pos, 1);
    }

    inline long long getDummy() {
        return dummy;
    }
private:
    struct TreeNode {
        int l, r;
        int sum;
    };

    int n;
    long long dummy;
    vector<TreeNode> nodes;
    vector<int> members;

    inline int lc(int x) {
        return x << 1;
    }

    inline int rc(int x) {
        return lc(x) + 1;
    }

    inline void pushUp(int x) {
        nodes[x].sum = nodes[lc(x)].sum + nodes[rc(x)].sum;
    }

    void build(int x, int l, int r) {
        nodes[x].l = l;
        nodes[x].r = r;
        if (l == r) {
            nodes[x].sum = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(x), l, mid);
        build(rc(x), mid + 1, r);
        pushUp(x);
    }

    int query(int x, int l, int r) {
        if (nodes[x].l == l && nodes[x].r == r) {
            return nodes[x].sum;
        }
        int mid = (nodes[x].l + nodes[x].r) >> 1;
        if (r <= mid) {
            return query(lc(x), l, r);
        }
        if (l > mid) {
            return query(rc(x), l, r);
        }
        return query(lc(x), l, mid) + query(rc(x), mid + 1, r);
    }

    void update(int x, int pos, int val) {
        nodes[x].sum += val;
        if (nodes[x].l == nodes[x].r) {
            return;
        }
        int mid = (nodes[x].l + nodes[x].r) >> 1;
        if (pos <= mid) {
            update(lc(x), pos, val);
        } else {
            update(rc(x), pos, val);
        }
    }

    int find(int x, int k) {
        if (nodes[x].l == nodes[x].r) {
            return nodes[x].l;
        }
        if (nodes[lc(x)].sum >= k) {
            return find(lc(x), k);
        }
        return find(rc(x), k - nodes[lc(x)].sum);
    }
};

int main() {
    char op[2];
    int val, pos;
    scanf("%d%d%d", &h, &m, &n);
    memset(posIdx, -1, sizeof(posIdx));
    vector<SegmentTree> trees;
    for (int i = 0; i < h; ++i) {
        if (posIdx[i] == -1) {
            int j = i;
            vector<int> members(1, 0);
            while (posIdx[j] == -1) {
                treeIdx[j] = trees.size();
                posIdx[j] = members.size();
                members.push_back(j);
                (j += m) %= h;
            }
            SegmentTree tree(members);
            trees.push_back(tree);
        }
    }
    map<int, int> valIdx, valPos;
    while (n--) {
        scanf("%s%d", op, &val);
        if (op[0] == '+') {
            scanf("%d", &pos);
            valIdx[val] = treeIdx[pos];
            valPos[val] = trees[treeIdx[pos]].add(posIdx[pos]);
        } else {
            trees[valIdx[val]].remove(valPos[val]);
            valIdx.erase(val);
            valPos.erase(val);
        }
    }
    long long dummy = 0;
    for (auto& tree : trees) {
        dummy += tree.getDummy();
    }
    cout << dummy << endl;
    return 0;
}
