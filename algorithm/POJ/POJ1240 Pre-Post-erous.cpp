#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len;
char pres[30],posts[30];

int C(int n, int k)
{
    int temp=1;
    if(k>(n>>1))
    {
        k=n-k;
    }
    for(int i=1;i<=k;++i)
    {
        temp=temp*(n-i+1)/i;
    }
    return temp;
}

int search(int l, char *pre, char *post)
{
    int left=1, right=0,child=0,temp=1;
    while(left<l)
    {
        ++child;
        while(pre[left]!=post[right])
        {
            ++right;
        }
        temp*=search(right-left+2, pre+left, post+left-1);
        left=right+2;
    }
    return temp*C(len, child);
}
int main()
{
    while(scanf("%d",&len),len)
    {
        scanf("%s%s",pres,posts);
        printf("%d\n",search(strlen(pres),pres,posts));
    }
	return 0;
}
