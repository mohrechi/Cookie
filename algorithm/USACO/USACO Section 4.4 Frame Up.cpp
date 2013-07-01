/*
ID: cyberzh1
LANG: C++
TASK: frameup
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("frameup.in","r");
FILE* fout=fopen("frameup.out","w");
bool appear[200],graph[26][26];
char character[26],map[35][35],ans[26];
int height,width,characterNum,in[26];
int posL[26], posR[26], posT[26], posB[26];
void input()
{
    fscanf(fin,"%d%d",&height,&width);
    for(int i=0;i<height;i++)
    {
        fscanf(fin,"%s",map[i]);
    }
}
void analysis()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            appear[map[i][j]]=true;
        }
    }
    for(int i='A';i<='Z';i++)
    {
        if(appear[i])
        {
            character[characterNum++]=i;
        }
    }
}
void initGraph()
{
    for(int i=0;i<characterNum;i++)
    {
        posL[i]=posT[i]=50;
        posR[i]=posB[i]=0;
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(map[i][j]!='.')
            {
                int k=-1;
                while(true)
                {
                    if(map[i][j]==character[++k])
                    {
                        break;
                    }
                }
                if(i<posT[k]) posT[k]=i;
                if(i>posB[k]) posB[k]=i;
                if(j<posL[k]) posL[k]=j;
                if(j>posR[k]) posR[k]=j;
            }
        }
    }
    for(int i=0;i<characterNum;i++)
    {
        for(int j=posL[i];j<=posR[i];j++)
        {
            if(map[posT[i]][j]!=character[i] and map[posT[i]][j]!='.')
            {
                int k=-1;
                while(true)
                {
                    if(map[posT[i]][j]==character[++k])
                    {
                        break;
                    }
                }
                graph[i][k]=true;
            }
            if(map[posB[i]][j]!=character[i] and map[posB[i]][j]!='.')
            {
                int k=-1;
                while(true)
                {
                    if(map[posB[i]][j]==character[++k])
                    {
                        break;
                    }
                }
                graph[i][k]=true;
            }
        }
        for(int j=posT[i];j<=posB[i];j++)
        {
            if(map[j][posL[i]]!=character[i] and map[j][posL[i]]!='.')
            {
                int k=-1;
                while(true)
                {
                    if(map[j][posL[i]]==character[++k])
                    {
                        break;
                    }
                }
                graph[i][k]=true;
            }
            if(map[j][posR[i]]!=character[i] and map[j][posR[i]]!='.')
            {
                int k=-1;
                while(true)
                {
                    if(map[j][posR[i]]==character[++k])
                    {
                        break;
                    }
                }
                graph[i][k]=true;
            }
        }
    }
    for(int i=0;i<characterNum;i++)
    {
        for(int j=0;j<characterNum;j++)
        {
            if(graph[i][j])
            {
                in[j]++;
            }
        }
    }
}
void output(int depth)
{
    for(int i=0;i<characterNum;i++)
    {
        if(in[i]==0)
        {
            ans[depth]=character[i];
            if(depth==characterNum)
            {
                fprintf(fout,"%s\n",ans+1);
            }
            in[i]=-1;
            for(int j=0;j<characterNum;j++)
            {
                if(graph[i][j])
                {
                    in[j]--;
                }
            }
            output(depth+1);
            for(int j=0;j<characterNum;j++)
            {
                if(graph[i][j])
                {
                    in[j]++;
                }
            }
            in[i]=0;
        }
    }
}
int main()
{
    input();
    analysis();
    initGraph();
    output(1);
    return 0;
}
