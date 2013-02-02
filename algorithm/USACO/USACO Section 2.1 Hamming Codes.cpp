/*
ID: cyberzh1
LANG: C++
TASK: hamming
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("hamming.in","r");
FILE* fout=fopen("hamming.out","w");
int N,B,D,dist[300][300],ans[100],max;
void dfs(int layer, int start)
{
    if(layer==N)
    {
        for(int i=0;i<N;i++)
        {
            if(i%10) fprintf(fout, " ");
            fprintf(fout,"%d",ans[i]);
            if(i%10==9 or i==N-1) fprintf(fout,"\n");
        }
        exit(0);
    }
    for(int i=start;i<max;i++)
    {
        int j;
        for(j=0;j<layer;j++)
        {
            if(dist[ans[j]][i]<D)
            {
                break;
            }
        }
        if(j==layer)
        {
            ans[layer]=i;
            dfs(layer+1,i+1);
        }
    }
}
int main()
{
    fscanf(fin,"%d%d%d",&N,&B,&D);
    max=(1<<B);
    for(int i=0;i<max;i++)
    {
        for(int j=i;j<max;j++)
        {
            dist[i][j]=0;
            for(int k=0;k<B;k++)
            {
                if((i&(1<<k))!=(j&(1<<k)))
                {
                    dist[i][j]++;
                }
            }
            dist[j][i]=dist[i][j];
        }
    }
    ans[0]=0;
    dfs(1,1);
    return 0;
}
