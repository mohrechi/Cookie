/*
ID: cyberzh1
LANG: C++
TASK: lgame
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
FILE* fin=fopen("lgame.in","r");
FILE* dic=fopen("lgame.dict","r");
FILE* fout=fopen("lgame.out","w");
int score[]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
char stdWord[10],dict[40000][10];
int dictNum,maxScore;
bool visited[9];
bool deal(char word[])
{
    int len=strlen(word);
    for(int i=0;i<len;i++)
    {
        int j;
        for(j=0;j<9;j++)
        {
            if(not visited[j] and word[i]==stdWord[j])
            {
                visited[j]=true;
                break;
            }
        }
        if(j==9)
        {
            return false;
        }
    }
    return true;
}
void input()
{
    fscanf(fin,"%s",stdWord);
    dictNum=0;
    while(fscanf(dic,"%s",dict[dictNum]),dict[dictNum][0]!='.')
    {
        memset(visited,0,sizeof(visited));
        if(deal(dict[dictNum]))
        {
            dictNum++;
        }
    }
}
void search()
{
    for(int i=0;i<dictNum;i++)
    {
        memset(visited,0,sizeof(visited));
        deal(dict[i]);
        int currentScore=0;
        for(int j=0;j<9;j++)
        {
            if(visited[j])
            {
                currentScore+=score[stdWord[j]-'a'];
            }
        }
        if(currentScore>maxScore)
        {
            maxScore=currentScore;
        }
        for(int j=i;j<dictNum;j++)
        {
            memset(visited,0,sizeof(visited));
            if(deal(dict[i]) and deal(dict[j]))
            {
                currentScore=0;
                for(int k=0;k<9;k++)
                {
                    if(visited[k])
                    {
                        currentScore+=score[stdWord[k]-'a'];
                    }
                }
                if(currentScore>maxScore)
                {
                    maxScore=currentScore;
                }
            }
        }
    }
}
void output()
{
    fprintf(fout,"%d\n",maxScore);
    for(int i=0;i<dictNum;i++)
    {
        memset(visited,0,sizeof(visited));
        deal(dict[i]);
        int currentScore=0;
        for(int j=0;j<9;j++)
        {
            if(visited[j])
            {
                currentScore+=score[stdWord[j]-'a'];
            }
        }
        if(currentScore==maxScore)
        {
            fprintf(fout,"%s\n",dict[i]);
        }
        for(int j=i;j<dictNum;j++)
        {
            memset(visited,0,sizeof(visited));
            if(deal(dict[i]) and deal(dict[j]))
            {
                currentScore=0;
                for(int k=0;k<9;k++)
                {
                    if(visited[k])
                    {
                        currentScore+=score[stdWord[k]-'a'];
                    }
                }
                if(currentScore==maxScore)
                {
                    fprintf(fout,"%s %s\n",dict[i],dict[j]);
                }
            }
        }
    }
}
int main()
{
    input();
    search();
    output();
    return 0;
}
