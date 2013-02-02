#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int n;
long long m;
long long f[21][21][2];

void read()
{
    scanf("%d%lld",&n,&m);
}

long long dp(int pos,int len,int inc)
{
    if(pos==1&&inc)
        return 0;
    if(len==1)
        return 1;
    int k;
    long long t,sum=0;
    if(inc)
    {
        t=0;
        if(f[pos-1][len][1])t=f[pos-1][len][1];
        else
            t=f[pos-1][len][1]=dp(pos-1,len,1);
        sum+=t;
        if(f[pos-1][len-1][0])t=f[pos-1][len-1][0];
        else
            t=f[pos-1][len-1][0]=dp(pos-1,len-1,0);
        sum+=t;
    }
    else
    {
        if(f[len+1-pos][len][1])t=f[len+1-pos][len][1];
        else t=f[len+1-pos][len][1]=dp(len+1-pos,len,1);
            sum=t;
    }
    return sum;
}

void solve(int n,long long re)
{
    int i,j,pos,dic;
    int set[21];
    for(i=1;i<=n;i++)
        set[i]=i;
    for(i=n;i>=1;--i)
    {
        if(i==n)
        {
            for(j=1;j<=i;++j)
            {
                if(re-f[j][i][1]<=0)
                {
                    pos=j;dic=1;break;
                }
                else
                    re-=f[j][i][1];
                if(re-f[j][i][0]<=0)
                {
                    pos=j;dic=0;break;
                }
                else
                    re-=f[j][i][0];
            }
            printf("%d",set[pos]);
            for(j=pos;j<=i;j++)
                set[j]=set[j+1];
        }
        else
        {
            if(dic==1)
            {
                for(j=1;j<pos;++j)
                {
                    if(re-f[j][i][0]<=0)
                    {
                        pos=j;dic=0;
                        break;
                    }
                    re-=f[j][i][0];
                }
                printf(" %d",set[pos]);
                for(j=pos;j<=i;j++)
                    set[j]=set[j+1];
            }
            else
            {
                for(j=pos;j<=i;++j)
                {
                    if(re-f[j][i][1]<=0)
                    {
                        pos=j;dic=1;
                        break;
                    }
                    re-=f[j][i][1];
                }
                printf(" %d",set[pos]);
                for(j=pos;j<=i;j++)
                    set[j]=set[j+1];
            }
        }
    }
    printf("\n");
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        read();
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;++i)
        {
            f[i][n][0]=dp(i,n,0);
            f[i][n][1]=dp(i,n,1);
        }
        solve(n,m);
    }
    return 0;
}
