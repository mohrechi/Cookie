#include<stdio.h>
#define Max 0x7FFFFFFF

int main()
{
    int map[105][105],dist[105][105],n;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                map[i][j]=Max;
            }
        }
        for(int i=1;i<=n;i++)
        {
            int j;
            scanf("%d",&j);
            while(j--)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                map[i][a]=b;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=map[i][j];
            }
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dist[i][k]!=Max and dist[k][j]!=Max)
                    {
                        if(dist[i][k]+dist[k][j]<dist[i][j])
                        {
                            dist[i][j]=dist[i][k]+dist[k][j];
                        }
                    }
                }
            }
        }
        int min=Max,person;
        for(int i=1;i<=n;i++)
        {
            int max=0;
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>max and i!=j)
                {
                    max=dist[i][j];
                }
            }
            if(max<min)
            {
                min=max;
                person=i;
            }
        }
        if(min==Max)
        {
            printf("disjoint\n");
        }
        else
        {
            printf("%d %d\n",person,min);
        }
    }
    return 0;
}
