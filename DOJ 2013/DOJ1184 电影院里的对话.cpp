#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXL = 10 + 1;
const int MAXM = 1e4 + 5;

struct Word
{
    char s[MAXL];
    long long key;
    void input()
    {
        key = 0;
        scanf("%s", s);
        for (int i = 0; s[i]; ++i)
        {
            int shift = 0;
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                shift = s[i] - 'a' + 1;
            }
            else
            {
                shift = s[i] - 'A' + 27;
            }
            key = key * 53 + shift;
        }
    }
} word[MAXN];

struct Query
{
    int l, r;
    int index;
    void input()
    {
        scanf("%d%d", &l, &r);
    }
    bool operator <(const Query &query) const
    {
        return r < query.r;
    }
} query[MAXM];

struct TreeNode
{
    int l, r;
    int sum;
} tree[MAXN * 3];

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = 0;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(x << 1, l, mid);
    buildTree((x << 1) + 1, mid + 1, r);
}

int queryTree(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        return tree[x].sum;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        return queryTree(x << 1, l, r);
    }
    if (l > mid)
    {
        return queryTree((x << 1) + 1, l, r);
    }
    return queryTree(x << 1, l, mid) + queryTree((x << 1) + 1, mid + 1, r);
}

void updateTree(int x, int pos, int value)
{
    tree[x].sum += value;
    if (tree[x].l == tree[x].r)
    {
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        updateTree(x << 1, pos, value);
    }
    else
    {
        updateTree((x << 1) + 1, pos, value);
    }
}

int ans[MAXM];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            word[i].input();
        }
        for (int i = 0; i < m; ++i)
        {
            query[i].input();
            query[i].index = i;
        }
        sort(query, query + m);
        buildTree(1, 1, n);
        int pos = 1;
        map<long long, int> last;
        for (int i = 0; i < m; ++i)
        {
            while (pos <= query[i].r)
            {
                if (last[word[pos].key])
                {
                    updateTree(1, last[word[pos].key], -1);
                }
                updateTree(1, pos, 1);
                last[word[pos].key] = pos;
                ++pos;
            }
            ans[query[i].index] = queryTree(1, query[i].l, query[i].r);
        }
        for (int i = 0; i < m; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
