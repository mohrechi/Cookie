#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int n, graph[1005][1005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&graph[i][j]);
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(graph[i-1][j-1]+graph[i][j]!=graph[i-1][j]+graph[i][j-1])
                {
                    flag=false;
                }
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
