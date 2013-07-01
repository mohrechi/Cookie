#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b)
{
    return strcmp((char*)a,(char*)b);
}
int t,n;
char s[10005][15];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        qsort(s,n,sizeof(*s),cmp);
        bool flag=true;
        for(int i=0;i<n-1;i++)
        {
            int len=strlen(s[i]);
            int j;
            for(j=0;j<len;j++)
            {
                if(s[i][j]!=s[i+1][j])
                {
                    break;
                }
            }
            if(j==len)
            {
                flag=false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
