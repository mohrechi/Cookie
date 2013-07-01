#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct T
{
    bool flag;
    int link[135],num;
}tree[60005];

int tNum;
char input[1500][50];

void init()
{
    tree[tNum].flag=false;
    tree[tNum].num=0;
    for(int i=0;i<130;i++)
    {
        tree[tNum].link[i]=-1;
    }
    tNum++;
}

void insert(char *s, int len)
{
    int temp=0;
    for(int i=0;i<len;i++)
    {
        if(tree[temp].link[s[i]]==-1)
        {
            init();
            tree[temp].link[s[i]]=tNum-1;
        }
        temp=tree[temp].link[s[i]];
        tree[temp].num++;
    }
    tree[temp].flag=true;
}

void find(char *s, int len)
{
    int temp=0;
    for(int i=0;i<len-1;i++)
    {
        temp=tree[temp].link[s[i]];
        if(tree[temp].num==1)
        {
            s[i+1]=0;
            break;
        }
    }
}

int main()
{
    int n=0;
    init();
    while(scanf("%s",input[n])!=EOF)
    {
        insert(input[n],strlen(input[n]));
        n++;
    }
    for(int i=0;i<n;i++)
    {
        printf("%s ",input[i]);
        find(input[i],strlen(input[i]));
        printf("%s\n",input[i]);
    }
    return 0;
}
