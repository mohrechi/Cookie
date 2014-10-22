/*
ID: cyberzh1
LANG: C++
TASK: fence
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("fence.in","r");
FILE* fout=fopen("fence.out","w");
int graph[505][505],result[2000],top;
void dfs(int n)
{
    for(int i=1;i<=500;i++)
    {
        if(graph[n][i])
        {
            graph[n][i]--;
            graph[i][n]--;
            dfs(i);
        }
    }
    result[top++]=n;
}
void output()
{
    while(top--)
    {
        fprintf(fout,"%d\n",result[top]);
    }
}
int main()
{
    int n,a,b;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d%d",&a,&b);
        graph[a][b]++;
        graph[b][a]++;
        graph[a][0]++;
        graph[b][0]++;
    }
    for(int i=1;i<=500;i++)
    {
        if(graph[i][0]&1)
        {
            dfs(i);
            output();
            return 0;
        }
    }
    dfs(1);
    output();
    return 0;
}
