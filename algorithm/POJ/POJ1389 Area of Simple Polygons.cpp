#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2010;
const int MAXM = 50010;

struct TreeNode
{
    int l, r, sum, value;
    bool lazy;
}tree[MAXN * 3];

struct Rect
{
    int l, r, b, t;
    inline void input()
    {
        scanf("%d%d%d%d",&l,&b,&r,&t);
    }
    inline bool valid()
    {
        return l + 1 || b + 1 || r + 1 || t + 1;
    }
}rect[MAXN];
int rectNumber;

struct Segment
{
    int x, b, t;
    bool in;
    void getLeft(const Rect &rect)
    {
        x = rect.l;
        b = rect.b;
        t = rect.t;
        in = true;
    }
    void getRight(const Rect &rect)
    {
        x = rect.r;
        b = rect.b;
        t = rect.t;
        in = false;
    }
    bool operator < (const Segment &segment) const
    {
        return x < segment.x;
    }
}segment[MAXN];
int segmentNumber;

struct Set
{
    int set[MAXN];
    int map[MAXM];
    int num;
    inline void clear()
    {
        num = 0;
    }
    inline void push(int x)
    {
        set[0] = -1;
        set[++ num] = x;
    }
    inline void push(const Rect &rect)
    {
        push(rect.b);
        push(rect.t);
    }
    inline void simplify()
    {
        sort(set + 1, set + num + 1);
        int j = 1;
        for(int i=1;i<=num;++i)
        {
            if(set[i] != set[i-1])
            {
                map[set[i]] = j;
                set[j++] = set[i];
            }
        }
        num = j - 1;
    }
}set;

inline int left(int x)
{
    return x << 1;
}

inline int right(int x)
{
    return (x << 1) + 1;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = 0;
    tree[x].lazy = false;
    tree[x].value = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(left(x), l, mid);
    build(right(x), mid + 1, r);
}

void relax(int x)
{
    if(tree[x].lazy)
    {
        tree[left(x)].value += tree[x].value;
        tree[right(x)].value += tree[x].value;
        tree[left(x)].lazy = true;
        tree[right(x)].lazy = true;
        if(tree[x].value)
        {
            tree[left(x)].sum = set.set[tree[left(x)].r + 1] - set.set[tree[left(x)].l];
            tree[right(x)].sum = set.set[tree[right(x)].r + 1] - set.set[tree[right(x)].l];
        }
        else
        {
            tree[left(x)].sum = 0;
            tree[right(x)].sum = 0;
        }
        tree[x].lazy = false;
        tree[x].value = 0;
    }
}

void update(int x, int l, int r, int value)
{
    if(value > 0)
    {
        if(tree[x].l == l && tree[x].r == r)
        {
            tree[x].value += value;
            tree[x].lazy = true;
            tree[x].sum = set.set[tree[x].r + 1] - set.set[tree[x].l];
            return;
        }
    }
    else
    {
        if(tree[x].l == tree[x].r)
        {
            tree[x].value += value;
            if(tree[x].value)
            {
                tree[x].sum = set.set[tree[x].r + 1] - set.set[tree[x].l];
            }
            else
            {
                tree[x].sum = 0;
            }
            return;
        }
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        update(left(x), l, r, value);
    }
    else if(l > mid)
    {
        update(right(x), l, r, value);
    }
    else
    {
        update(left(x), l, mid, value);
        update(right(x), mid + 1, r, value);
    }
    tree[x].sum = tree[left(x)].sum + tree[right(x)].sum;
}

int query(int x, int pos)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x].value;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid)
    {
        return query(left(x), pos);
    }
    else
    {
        return query(right(x), pos);
    }
}

int main()
{
    while(rect[0].input(), rect[0].valid())
    {
        segmentNumber = 0;
        segment[segmentNumber ++].getLeft(rect[0]);
        segment[segmentNumber ++].getRight(rect[0]);
        rectNumber = 1;
        set.clear();
        set.push(rect[0]);
        while(rect[rectNumber].input(), rect[rectNumber].valid())
        {
            set.push(rect[rectNumber]);
            segment[segmentNumber ++].getLeft(rect[rectNumber]);
            segment[segmentNumber ++].getRight(rect[rectNumber]);
            ++ rectNumber;
        }
        set.simplify();
        build(1, 1, set.num);
        sort(segment, segment + segmentNumber);
        long long ans = 0;
        for(int i=0;i<segmentNumber;++i)
        {
            if(i)
            {
                ans += (segment[i].x - segment[i-1].x) * 1LL * tree[1].sum;
            }
            if(segment[i].in)
            {
                update(1, set.map[segment[i].b], set.map[segment[i].t] - 1, 1);
            }
            else
            {
                update(1, set.map[segment[i].b], set.map[segment[i].t] - 1, -1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
