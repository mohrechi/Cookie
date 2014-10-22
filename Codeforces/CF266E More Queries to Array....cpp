#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 6;
const int MOD = 1000000007;

int n, m;
long long a[MAXN];
long long c[MAXM][MAXM];
long long p[MAXN][MAXM], psum[MAXN][MAXM];

void init()
{
    c[0][0] = 1;
    for(int i = 1; i < MAXM; ++ i)
    {
        for(int j = 0; j <= i; ++ j)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for(int i = 1; i < MAXN; ++ i)
    {
        long long temp = 1;
        for(int j = 0;j < MAXM; ++ j)
        {
            p[i][j] = temp;
            psum[i][j] = (psum[i - 1][j] + p[i][j]) % MOD;
            temp = (temp * i) % MOD;
        }
    }
}

struct TreeNode
{
    int l, r, lazy;
    long long sum[MAXM];
} tree[MAXN * 3];

inline int lc(const int &x)
{
    return x << 1;
}

inline int rc(const int &x)
{
    return (x << 1) + 1;
}

void combine(int x)
{
    for(int i = 0; i < MAXM; ++ i)
    {
        tree[x].sum[i] = (tree[lc(x)].sum[i] + tree[rc(x)].sum[i]) % MOD;
    }
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = -1;
    if(l == r)
    {
        for(int i = 0; i < MAXM; ++ i)
        {
            tree[x].sum[i] = (a[l] * p[l][i]) % MOD;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    combine(x);
}

void relax(int x)
{
    if(tree[x].lazy != -1)
    {
        int l = tree[x].l;
        int r = tree[x].r;
        int mid = (tree[x].l + tree[x].r) >> 1;
        for(int i = 0; i < MAXM; ++ i)
        {
            tree[lc(x)].sum[i] = (tree[x].lazy * ((psum[mid][i] - psum[l - 1][i] + MOD) % MOD)) % MOD;
            tree[rc(x)].sum[i] = (tree[x].lazy * ((psum[r][i] - psum[mid][i] + MOD) % MOD)) % MOD;
        }
        tree[lc(x)].lazy = tree[x].lazy;
        tree[rc(x)].lazy = tree[x].lazy;
        tree[x].lazy = -1;
    }
}

void update(int x, int l, int r, int value)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        tree[x].lazy = value;
        for(int i = 0; i < MAXM; ++ i)
        {
            tree[x].sum[i] = (value * ((psum[r][i] - psum[l - 1][i] + MOD) % MOD)) % MOD;
        }
        return;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        update(lc(x), l, r, value);
    }
    else if(l > mid)
    {
        update(rc(x), l, r, value);
    }
    else
    {
        update(lc(x), l, mid, value);
        update(rc(x), mid + 1, r, value);
    }
    combine(x);
}

long long query(int x, int l, int r, int k)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        return tree[x].sum[k];
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        return query(lc(x), l, r, k);
    }
    else if(l > mid)
    {
        return query(rc(x), l, r, k);
    }
    else
    {
        return (query(lc(x), l, mid, k) + query(rc(x), mid + 1, r, k)) % MOD;
    }
}

long long query(int l, int r, int k)
{
    long long ans = 0;
    long long temp = 1;
    for(int i = 0; i <= k; ++ i)
    {
        ans = (ans + (((query(1, l, r, k - i) * c[k][i]) % MOD) * temp) % MOD) % MOD;
        temp = (temp * (1 - l)) % MOD;
    }
    return (ans + MOD) % MOD;
}

int main()
{
    char op[10];
    int l, r, x;
    init();
    while(~scanf("%d%d", &n, &m))
    {
        for(int i = 1; i <= n; ++ i)
        {
            scanf("%I64d", &a[i]);
        }
        build(1, 1, n);
        while(m --)
        {
            scanf("%s%d%d%d", op, &l, &r, &x);
            if(op[0] == '?')
            {
                printf("%I64d\n", query(l, r, x));
            }
            else
            {
                update(1, l, r, x);
            }
        }
    }
    return 0;
}
