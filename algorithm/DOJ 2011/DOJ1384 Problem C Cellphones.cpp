#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int n,a[5005],b[5005],c[5005];
bool visited[5005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++)
        {
            if(visited[i])
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(visited[j])
                {
                    continue;
                }
                if(a[i]<=a[j] && b[i]<=b[j] && c[i]<=c[j])
                {
                    visited[j]=true;
                }
                else if(a[i]>=a[j] && b[i]>=b[j] && c[i]>=c[j])
                {
                    visited[i]=true;
                }
            }
        }
        int answer=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                answer++;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
