class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0) {
            return vector<pair<int, int>>();
        }
        set<int> vals;
        for (auto building : buildings) {
            vals.insert(building[0]);
            vals.insert(building[1]);
        }
        int m = vals.size();
        map<int, int> idx;
        vector<int> ori(m);
        int id = 0;
        for (auto val : vals) {
            idx[val] = id;
            ori[id] = val;
            ++id;
        }
        build(1, 0, m - 1);
        for (auto building : buildings) {
            update(1, idx[building[0]], idx[building[1]] - 1, building[2]);
        }
        vector<pair<int, int>> skyline;
        int last = -1;
        for (int i = 0; i < m; ++i) {
            int tmp = query(1, i);
            if (tmp != last) {
                last = tmp;
                skyline.push_back(pair<int, int>(ori[i], tmp));
            }
        }
        return skyline;
    }
private:
    struct TreeNode {
        int l, r, val;
    } tree[10005 * 6];

    inline int lc(int x) {
        return x << 1;
    }

    inline int rc(int x) {
        return lc(x) + 1;
    }

    void build(int x, int l, int r) {
        tree[x] = {l, r, 0};
        if (l == r) {
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(x), l, mid);
        build(rc(x), mid + 1, r);
    }

    void push(int x) {
        if (tree[x].val) {
            tree[lc(x)].val = max(tree[lc(x)].val, tree[x].val);
            tree[rc(x)].val = max(tree[rc(x)].val, tree[x].val);
            tree[x].val = 0;
        }
    }

    void update(int x, int l, int r, int h) {
        if (tree[x].l == l and tree[x].r == r) {
            tree[x].val = max(tree[x].val, h);
            return;
        }
        push(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (r <= mid) {
            update(lc(x), l, r, h);
        } else if (l > mid) {
            update(rc(x), l, r, h);
        } else {
            update(lc(x), l, mid, h);
            update(rc(x), mid + 1, r, h);
        }
    }

    int query(int x, int pos) {
        if (tree[x].l == tree[x].r) {
            return tree[x].val;
        }
        push(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (pos <= mid) {
            return query(lc(x), pos);
        }
        return query(rc(x), pos);
    }
};
