/*
ID: cyberzh1
LANG: C++
TASK: tour
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE* fin=fopen("tour.in","r");
FILE* fout=fopen("tour.out","w");
int n,m,path[105][105],answer;
bool graph[105][105];
char cityName[105][30];
void input()
{
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%s",&cityName[i]);
    }
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%s%s",cityName[103],cityName[104]);
        int j,k;
        for(j=0;j<n;j++)
        {
            if(not strcmp(cityName[103],cityName[j]))
            {
                break;
            }
        }
        for(k=0;k<n;k++)
        {
            if(not strcmp(cityName[104],cityName[k]))
            {
                break;
            }
        }
        graph[k][j]=graph[j][k]=true;
    }
}
void calc()
{
    path[0][0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            path[i][j]=-1;
            for(int k=0;k<j;k++)
            {
                if(graph[k][j] and path[i][k]>0 and path[i][k]>path[i][j])
                {
                    path[i][j]=path[i][k];
                }
            }
            path[j][i]=++path[i][j];
        }
    }
    answer=1;
    for(int i=0;i<n;i++)
    {
        if(graph[i][n-1] and path[i][n-1]>answer)
        {
            answer=path[i][n-1];
        }
    }
    fprintf(fout,"%d\n",answer);
}
int main()
{
    input();
    calc();
    return 0;
}
