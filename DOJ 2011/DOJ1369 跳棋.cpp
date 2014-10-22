#include<stdio.h>
#include<stdlib.h>
int graph[100][100],t,s,p,n,a[50],b[50],point[100];
int main()
{
    while(scanf("%d%d%d",&t,&s,&p)!=EOF)
    {
        n=0;
        point[n++]=0;
        for(int i=0;i<p;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            bool flag1=true, flag2=true;
            for(int j=0;j<n;j++)
            {
                if(a[i]==point[j])
                {
                    flag1=false;
                }
                if(b[i]==point[j])
                {
                    flag2=false;
                }
            }
            if(flag1)
            {
                point[n++]=a[i];
            }
            if(flag2)
            {
                point[n++]=b[i];
            }
        }
        point[n++]=t;
        int temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp=point[i]-point[j];
                if(temp<0)
                {
                    temp=-temp;
                }
                graph[i][j]=(temp+s-1)/s;
            }
        }
        for(int i=0;i<p;i++)
        {
            int x,y;
            for(int j=0;j<n;j++)
            {
                if(a[i]==point[j])
                {
                    x=j;
                }
                if(b[i]==point[j])
                {
                    y=j;
                }
            }
            graph[x][y]=0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(graph[i][j]>graph[i][k]+graph[k][j])
                    {
                        graph[i][j]=graph[i][k]+graph[k][j];
                    }
                }
            }
        }
        printf("%d\n",graph[0][n-1]);
    }
    return 0;
}
