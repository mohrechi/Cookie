/*
ID: cyberzh1
LANG: C++
TASK: comehome
*/
#include<stdio.h>
FILE* fin=fopen("comehome.in","r");
FILE* fout=fopen("comehome.out","w");
int graph[100][100],home;
int find(char ch)
{
    if(ch>='A' and ch<='Z')
    {
        return ch-'A'+26;
    }
    else return ch-'a';
}
void connect(char ch1, char ch2, int length)
{
    int u,v;
    u=find(ch1),v=find(ch2);
    if(length<graph[u][v])
    {
        graph[u][v]=graph[v][u]=length;
    }
}
void Floyd()
{
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
        {
            for(int k=0;k<52;k++)
            {
                if(graph[i][k]+graph[k][j]<graph[i][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
}
int main()
{
    int t,len;
    fscanf(fin,"%d",&t);
    for(int i=0;i<52;i++)
    {
        for(int j=0;j<52;j++)
        {
            graph[i][j]=1000000000;
        }
        graph[i][i]=0;
    }
    while(t--)
    {
        char s1[10],s2[10];
        int len;
        fscanf(fin,"%s%s%d",s1,s2,&len);
        connect(*s1,*s2,len);
    }
    Floyd();
    int min=0x7FFFFFFF,p;
    for(int i=26;i<51;i++)
    {
        if(graph[i][51]<min)
        {
            min=graph[i][51];
            p=i;
        }
    }
    p=p-26+'A';
    fprintf(fout,"%c %d\n",p,min);
    return 0;
}
