#include <cstdio>
#include <cstring>
static const int MAXN = 15;

int a[MAXN], n;
int ans[MAXN];

void dfs(int index, int depth)
{
    if(depth == 6)
    {
        printf("%d", ans[0]);
        for(int i=1;i<6;++i)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=index;i<n;++i)
    {
        ans[depth] = a[i];
        dfs(i+1, depth+1);
    }
}

int main()
{
    bool flag = false;
    while(scanf("%d",&n), n)
    {
        if(flag)
        {
            printf("\n");
        }
        else
        {
            flag = true;
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        dfs(0, 0);
    }
    return 0;
}
