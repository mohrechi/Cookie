#include<stdio.h>

main()
{
    int n,m,t[1001],c[1001],g[1001],i,j,k,e[1001];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&t[i],&c[i]);
            switch(c[i])
            {
                case 1:e[i]=13;break;
                case 2:e[i]=25;break;
                case 3:e[i]=-123;break;
            }
        }
        t[i]=1001;
        j=1,g[0]=0,k=1;
        while(j<=1000)
        {
            g[j]=g[j-1]+1;
            for(k=1;k<=n;k++)
            {
                if(j==t[k])
                {
                    g[j]+=e[k];
                    if(g[j]<0)
                    {
                        g[j]=0;
                    }
                }
            }
            j++;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&c[i]);

            printf("%d\n",g[c[i]]);
        }
    }
    return 0;
}
