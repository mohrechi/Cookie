#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char mod[400005];
int next[400005], stack[400005],len;
void get()
{
    int i,j;
    next[1]=0;
    j=0;
    for(i=2;i<=len;i++)
    {
        while(j>0 && mod[j+1]!=mod[i]) j=next[j];
        if(mod[j+1]==mod[i]) j++;
        next[i]=j;
    }
}
int main()
{
    while(scanf("%s",mod+1)!=EOF)
    {
        len=strlen(mod+1);
        get();
        int j=len,top=0;
        while(j)
        {
            stack[top++]=j;
            j=next[j];
        }
        for(j=top-1;j>0;j--)
        {
            printf("%d ",stack[j]);
        }
        printf("%d\n",stack[0]);
    }
    return 0;
}
