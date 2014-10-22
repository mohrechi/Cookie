#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
int caseNum,len,l[255];
char s[20],ans[20];
bool v[20];

void init()
{
    for(int i='A';i<='Z';i++)
    {
        l[i]=(i-'A')*2;
    }
    for(int i='a';i<='z';i++)
    {
        l[i]=(i-'a')*2+1;
    }
}

void sort()
{
    for(int i=0;i<len;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(l[s[i]]>l[s[j]])
            {
                s[i]^=s[j], s[j]^=s[i], s[i]^=s[j];
            }
        }
    }
}

void dfs(int num)
{
    if(num==len)
    {
        printf("%s\n",ans);
        return;
    }
    for(int i=0;i<len;i++)
    {
        if(!v[i])
        {
            v[i]=true;
            ans[num]=s[i];
            dfs(num+1);
            v[i]=false;
            while(s[i]==s[i+1])
            {
                i++;
            }
        }
    }
}

int main()
{
    scanf("%d",&caseNum);
    init();
    while(caseNum--)
    {
        scanf("%s",s);
        len=strlen(s);
        sort();
        memset(v,false,sizeof(v));
        ans[len]=0;
        dfs(0);
    }
    return 0;
}
