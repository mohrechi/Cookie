#include <cstdio>
static const int MAXN = 21;
int father[MAXN], parity[MAXN];
int n, m;

void init()
{
    for(int i=1;i<=n;++i)
    {
        father[i] = i;
        parity[i] = 0;
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    int temp = father[x];
    father[x] = find(father[x]);
    parity[x] ^= parity[temp];
    return father[x];
}

bool check(int x, int y, int p)
{
    int u = find(x);
    int v = find(y);
    if(u == v)
    {
        return parity[x]^parity[y] == p;
    }
    else
    {
        father[v] = u;
        parity[v] = parity[x]^parity[y]^p;
    }
    return true;
}

int main()
{
    int x, y, p;
    while(~scanf("%d%d",&n,&m))
    {
        bool flag = true;
        init();
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&p);
            if(flag)
            {
                flag = check(x,y,p);
            }
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
