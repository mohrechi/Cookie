#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000;

int stack[MAXN], top, i, j;
int maxi, now, k, prev, tprev;
int h[MAXN], n;
__int64 sum[MAXN], f[MAXN][10], addh, result;

int push(int vi)
{
    while(top && h[stack[top-1]]<h[vi])
    {
        top--;
    }
    stack[top++] = vi;
    return stack[top-2];
}

int ef(int vi,int addh)
{
    int l = 0,r = top-1,m,res = 0;
    if(h[maxi]<=h[vi]+addh)
    {
        return maxi;
    }
    while(l<r)
    {
        m = (l+r)>>1;
        if(h[stack[m]]<=h[vi]+addh)
        {
            r = m-1;
        }
        else
        {
            l = m+1;
            res=m;
        }
    }
    return stack[res];
}
int main()
{
    while(~scanf("%d%d",&n,&addh))
    {
        memset(f,0,sizeof(f));
        for(i=0,maxi=n;i<n;i++)
        {
            scanf("%d",&h[i]);
            h[i+n] = h[i+n+n] = h[i];
            if(h[maxi]<h[i+n])maxi = i+n;
        }
        for(i=1,sum[0] = h[0];i<n*3;i++)
        {
            sum[i] = sum[i-1] + h[i];
        }
        stack[0] = maxi;
        top = 1;
        for(now=maxi+1;now<maxi+n;now++)
        {
            prev = push(now);
            f[now][0] = f[prev][0] + (__int64)h[now] * (now-prev-1)-(sum[now-1]-sum[prev]);
            for(j=0;j<=addh;j++)
            {
                for(k=0;k<=j;k++)
                {
                    f[now][j] = f[prev][j] + (__int64)h[now] * (now-prev-1)-(sum[now-1]-sum[prev]);
                    tprev = ef(now,k);
                    f[now][j] = max(f[tprev][j-k] + min((__int64)(h[now]+k),(__int64)h[tprev]) * (now-tprev-1)-(sum[now-1]-sum[tprev]),f[now][j]);
                }
            }
        }
        top = 1;
        for(now=maxi-1;now>maxi-n;now--)
        {
            prev = push(now);
            f[now][0] = f[prev][0] + (__int64)h[now] * (prev-now-1)-(sum[prev-1]-sum[now]);
            for(j=1;j<=addh;j++)
            {
                for(k=0;k<=j;k++)
                {
                    f[now][j] = f[prev][j] + (__int64)h[now] * (prev-now-1)-(sum[prev-1]-sum[now]);
                    tprev = ef(now,k);
                    f[now][j] = max(f[tprev][j-k] + min((__int64)(h[now]+k),(__int64)h[tprev]) * (tprev-now-1)-((__int64)sum[tprev-1]-sum[now]),f[now][j]);
                }
            }
        }
        result = 0;
        for(i=0;i<n;i++)
        {
            for(k=0;k<=addh;k++)
            {
                result = max(result,f[maxi-i][k]+f[maxi+n-i-1][addh-k]);
            }
        }
        printf("%I64d\n",result);
    }
}
