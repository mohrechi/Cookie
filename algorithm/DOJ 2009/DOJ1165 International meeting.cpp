#include <cstdio>
#include <cstring>
static const int MAXN = 500010;
static const int factorMax[] = {
    1,      2,      4,      6,      12,
    24,     36,     48,     60,     120,
    180,    240,    360,    720,    840,
    1260,   1680,   2520,   5040,   7560,
    10080,  15120,  20160,  25200,  27720,
    45360,  50400,  55440,  83160,  110880,
    166320, 221760, 277200, 332640, 498960};
static const int factorNumber[] = {
    1,  2,  3,  4,  6,
    8,  9,  10, 12, 16,
    18, 20, 24, 30, 32,
    36, 40, 48, 60, 64,
    72, 80, 84, 90, 96,
    100,108,120,128,144,
    160,168,180,192,200};
int n, k;
char name[MAXN][15];
int next[MAXN];

inline int abs(int x)
{
    return x > 0 ? x : -x;
}

struct TreeNode
{
    int l, r;
    int num;
}tree[MAXN * 3];

void build(int x, int left, int right)
{
    tree[x].l = left;
    tree[x].r = right;
    tree[x].num = right - left + 1;
    if(tree[x].num > 1)
    {
        int mid = (left + right) >> 1;
        x <<= 1;
        build(x, left, mid);
        build(x+1, mid+1, right);
    }
}

void update(int x, int pos)
{
    -- tree[x].num;
    if(tree[x].l == tree[x].r)
    {
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(pos <= mid)
    {
        update(x, pos);
    }
    else
    {
        update(x+1, pos);
    }
}

int query(int x, int num)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x].l;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(num <= tree[x].num)
    {
        return query(x, num);
    }
    else
    {
        return query(x+1, num - tree[x].num);
    }
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%s%d", name[i], &next[i]);
        }
        int final;
        for(final=1;final<35;++final)
        {
            if(n < factorMax[final])
            {
                break;
            }
        }
        -- final;
        build(1, 1, n);
        update(1, k);
        int pos = k - 1;
        for(int i=1;i<factorMax[final];++i)
        {
            int temp;
            if(next[k] > 0)
            {
                pos = (pos + (next[k] % (n - i)) + n - i - 1) % (n - i);
            }
            else
            {
                pos = (pos + (next[k] % (n - i)) + n - i) % (n - i);
            }
            k = query(1, pos + 1);
            update(1, k);
        }
        printf("%s %d\n", name[k], factorNumber[final]);
    }
    return 0;
}
