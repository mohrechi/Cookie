#include<stdio.h>
#include<memory.h>

int n,k,c;
bool chess[10][10],h[10],s[10];

void dfs(int num, int index)
{
    if(num==k)
    {
        c++;
        return ;
    }
    int i=index/n, j=index%n;
    bool flag=true;
    for(;i<n;i++)
    {
        if(flag)
        {
            flag=false;
        }
        else
        {
            j=0;
        }
        for(;j<n;j++)
        {
            if(chess[i][j]&&!h[j]&&!s[i])
            {
                h[j]=true, s[i]=true;
                dfs(num+1, i*n+j+1);
                h[j]=false, s[i]=false;
            }
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&k),n+1||k+1)
    {
        char ch;
        c=0;
        memset(h,false,sizeof(h));
        memset(s,false,sizeof(s));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;)
            {
                scanf("%c",&ch);
                if(ch=='#')
                {
                    chess[i][j++]=true;
                }
                else if(ch=='.')
                {
                    chess[i][j++]=false;
                }
            }
        }
        dfs(0,0);
        printf("%d\n",c);
    }
    return 0;
}
