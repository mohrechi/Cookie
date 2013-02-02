#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int n,in[105],out[105],connect[105];
bool graph[105][105],copy[105][105];
int main()
{
    scanf("%d",&n);
    int temp;
    for(int i=1;i<=n;i++)
    {
        while(scanf("%d",&temp),temp)
        {
            graph[i][temp]=true;
            in[temp]++, out[i]++;
        }
    }
    memcpy(copy,graph,sizeof(graph));
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(graph[i][k] and graph[k][j])
                {
                    graph[i][j]=true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(connect[i])
        {
            in[connect[i]]+=in[i];
            out[connect[i]]+=out[i];
        }
        else
        {
            connect[i]=i;
        }
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j] and graph[j][i])
            {
                connect[j]=connect[i];
                if(copy[i][j])
                {
                    in[connect[i]]--;
                    out[connect[i]]--;
                }
            }
        }
    }
    int ans=0,inNum=0,outNum=0;
    for(int i=1;i<=n;i++)
    {
        if(connect[i]==i)
        {
            ans++;
            if(not in[i]) inNum++;
            if(not out[i]) outNum++;
        }
    }
    if(ans==1)
    {
        printf("1\n0\n");
    }
    else
    {
        printf("%d\n%d\n",inNum,inNum>outNum?inNum:outNum);
    }
	return 0;
}
