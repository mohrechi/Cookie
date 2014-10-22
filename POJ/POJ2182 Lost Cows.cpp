#include <cstdio>
static const int MAXN = 8005;
struct Node
{
    int l, r, w;
}node[MAXN * 4];
int n;
int a[MAXN];
int ans[MAXN];
int ansNumber;

void build(int l, int r, int x)
{
    node[x].l = l;
    node[x].r = r;
    node[x].w = r - l + 1;
    if(l<r)
    {
        build(l, ((l+r)>>1), x<<1);
        build(((l+r)>>1)+1, r, (x<<1)+1);
    }
}

void find(int x, int w)
{
    if(node[x].l == node[x].r)
    {
        ans[ansNumber++] = node[x].l;
        node[x].w = 0;
        return;
    }
    if(w <= node[x<<1].w)
    {
        find(x<<1, w);
    }
    else
    {
        find((x<<1)+1, w-node[x<<1].w);
    }
    --node[x].w;
}

int main()
{
    scanf("%d",&n);
    a[1] = 0;
    for(int i=2;i<=n;++i)
    {
        scanf("%d",&a[i]);
    }
    build(1, n, 1);
    ansNumber = 1;
    for(int i=n;i>=1;--i)
    {
        find(1, a[i]+1);
    }
    for(int i=n;i>=1;--i)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}
