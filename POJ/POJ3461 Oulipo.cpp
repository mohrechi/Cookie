#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int caseNum,len1,len2, next[10005];
char mod[10005], s[1000005];

void get()
{
    int i,j;
    next[1]=0;
    j=0;
    for(i=2;i<=len2;i++)
    {
        while(j>0 && mod[j+1]!=mod[i]) j=next[j];
        if(mod[j+1]==mod[i]) j++;
        next[i]=j;
    }
}

int KMP(int pos=1)
{
    int i,j,k;
    get();
    i=pos,k=0,j=0;
    while(i<=len1)
    {
        while(j>0 && mod[j+1]!=s[i]) j=next[j];
        if(mod[j+1]==s[i])
        {
            j++;
            if(j==len2) k++;
        }
        i++;
    }
    return k;
}

int main()
{
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%s%s",mod+1,s+1);
        len1=strlen(s+1);
        len2=strlen(mod+1);
        printf("%d\n",KMP());
    }
    return 0;
}
