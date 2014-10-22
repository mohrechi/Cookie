#include <cstdio>
#include <cstring>
const int MAXN = 100010;
const int INF = 0x7FFFFFFF;

struct TreeNode
{
    int l, r, sum;
}tree[MAXN * 4];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid);
    build((x<<1)+1, mid+1, r);
}

void insert(int x, int l, int r, int pos, int value)
{
    if(tree[x].l == tree[x].r)
    {
        tree[x].sum += value;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid)
    {
        insert(x<<1, l, mid, pos, value);
    }
    else
    {
        insert((x<<1)+1, mid+1, r, pos, value);
    }
    tree[x].sum = tree[x<<1].sum + tree[(x<<1)+1].sum;
}

int query(int x, int l, int r, int pos)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x].sum;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid)
    {
        query(x<<1, l, mid, pos);
    }
    else
    {
        query((x<<1)+1, mid+1, r, pos);
    }
}

int search(int x, int l, int r, int dir)
{
    int temp;
    if(tree[x].l == tree[x].r)
    {
        if(tree[x].l >= l && tree[x].r <= r)
        {
            return tree[x].l;
        }
        return -1;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        if(tree[x<<1].sum)
        {
            temp = search(x<<1, l, r, dir);
            if(temp != -1)
            {
                return temp;
            }
        }
    }
    else if(l > mid)
    {
        if(tree[(x<<1)+1].sum)
        {
            temp = search((x<<1)+1, l, r, dir);
            if(temp != -1)
            {
                return temp;
            }
        }
    }
    else
    {
        if(dir == 1)
        {
            if(tree[x<<1].sum)
            {
                temp = search(x<<1, l, mid, dir);
                if(temp != -1)
                {
                    return temp;
                }
            }
            if(tree[(x<<1)+1].sum)
            {
                temp = search((x<<1)+1, mid+1, r, dir);
                if(temp != -1)
                {
                    return temp;
                }
            }
        }
        else
        {
            if(tree[(x<<1)+1].sum)
            {
                temp = search((x<<1)+1, mid+1, r, dir);
                if(temp != -1)
                {
                    return temp;
                }
            }
            if(tree[x<<1].sum)
            {
                temp = search(x<<1, l, mid, dir);
                if(temp != -1)
                {
                    return temp;
                }
            }
        }
    }
    return -1;
}

inline int abs(int x)
{
    return x >= 0 ? x : -x;
}

int main()
{
    int t, l, n, op;
    scanf("%d", &t);
    for(int k=1;k<=t;++k)
    {
        int len = 0;
        int pos = 0;
        int dir = 1;
        scanf("%d%d",&l,&n);
        build(1, 1, l + 1);
        while(n--)
        {
            scanf("%d", &op);
            if(op == 0)
            {
                scanf("%d", &op);
                insert(1, 1, l+1, op + 1, 1);
            }
            else
            {
                if(tree[1].sum == 0)
                {
                    continue;
                }
                int spos, spos2;
                if(dir == 1)
                {
                    spos = search(1, pos + 1, l + 1, 1);
                    spos2 = search(1, 1, pos + 1, 0);
                    if(spos == -1)
                    {
                        spos = spos2;
                    }
                    else if(spos2 != -1 && abs(spos2 - 1 - pos) < abs(spos - 1 - pos))
                    {
                        spos = spos2;
                    }
                    -- spos;
                }
                else
                {
                    spos = search(1, 1, pos + 1, 0);
                    spos2 = search(1, pos + 1, l + 1, 1);
                    if(spos == -1)
                    {
                        spos = spos2;
                    }
                    else if(spos2 != -1 && abs(spos2 - 1 - pos) < abs(spos - 1 - pos))
                    {
                        spos = spos2;
                    }
                    -- spos;
                }
                //printf("Test: %d %d %d\n", pos, spos, spos2);
                len += abs(pos - spos);
                if(spos > pos)
                {
                    dir = 1;
                }
                else if(spos < pos)
                {
                    dir = 0;
                }
                pos = spos;
                insert(1, 1, l + 1, spos + 1, -1);
            }
            /*printf("Tree: \n");
            for(int i=1;i<=l+1;++i)
            {
                printf("%d ", query(1, 1, l + 1, i));
            }
            printf("\n");*/
        }
        printf("Case %d: %d\n", k, len);
    }
    return 0;
}
