#include<stdio.h>

int a[1005][1005];
int v[1005];
int d[1005];

int dijkstra(int t, int f)
{
    int i,j,k,min;
    for(i=1;i<=f;i++)
    {
        d[i]=a[t][i];
        v[i]=0;
    }
    d[t]=0,v[t]=1;
    for(i=1;i<f;i++)
    {
        for(min=2100000000,k=1,j=1;j<=f;j++)
        {
            if(!v[j]&&d[j]<min&&d[j]>0)
            {
                k=j,min=d[j];
            }
        }
        v[k]=1;
        for(j=1;j<=f;j++)
        {
            if(!v[j]&&d[k]+a[k][j]<d[j]&&a[k][j]<2100000000)
            {
                d[j]=a[k][j]+d[k];
            }
        }
    }
    return d[f];
}

int main(int argc, char* argv[])
{
    int i,j,t,n,x,y,z;
    scanf("%d%d",&t,&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            a[i][j]=2100000000;
        }
    }
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(z<a[x][y])a[x][y]=a[y][x]=z;
    }
    printf("%d\n",dijkstra(1,n));
	return 0;
}
