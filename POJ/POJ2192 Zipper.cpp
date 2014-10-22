#include<stdio.h>
#include<string.h>
char a[300],b[300],c[500];
int la,lb,lc;
bool dfs(int x, int y, int z)
{
    if(x==la && y==lb)
    {
        return true;
    }
    if(y<lb && b[y]==c[z])
    {
        if(dfs(x,y+1,z+1))
        {
            return true;
        }
    }
    if(x<la && a[x]==c[z])
    {
        if(dfs(x+1,y,z+1))
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%s%s",a,b,c);
        la=strlen(a);
        lb=strlen(b);
        lc=strlen(c);
        printf("Data set %d: ",i);
        if(la+lb!=lc || (a[la-1]!=c[lc-1] && b[lb-1]!=c[lc-1]))
        {
            printf("no\n");
            continue;
        }
        if(dfs(0,0,0)) printf("yes\n");
        else printf("no\n");
    }
}
