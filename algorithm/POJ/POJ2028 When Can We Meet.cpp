#include <cstdio>
#include <cstring>

int main(int argc, char *argv[])
{
    int n,q,m,a[105],t, p;
    while(scanf("%d%d",&n,&q), n || q)
    {
        memset(a, 0, sizeof(a));
        for(int i=0;i<n;++i)
        {
            scanf("%d",&m);
            for(int j=0;j<m;++j)
            {
                scanf("%d",&t);
                ++a[t];
            }
        }
        m = 0, p = 0;
        for(int i=1;i<105;++i)
        {
            if(a[i] >= q && a[i] > m)
            {
                m = a[i];
                p = i;
            }
        }
        printf("%d\n",p);
    }
    return 0;
}
