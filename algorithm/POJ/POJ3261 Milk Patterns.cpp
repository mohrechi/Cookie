#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20005;
const int MAXM = 20005;

int sa[MAXN], lcp[MAXN];
int rank[MAXN], rankY[MAXN];
int cnt[MAXN];

inline bool isRankSame(int rank[], int x, int y, int step)
{
    return rank[x] == rank[y] && rank[x + step] == rank[y + step];
}

void calcSA(int a[], int n, int m)
{
    int *x = rank, *y = rankY, *t;
    for(int i=0;i<m;++i)
    {
        cnt[i] = 0;
    }
    for(int i=0;i<n;++i)
    {
        x[i] = a[i];
        ++ cnt[x[i]];
    }
    for(int i=1;i<m;++i)
    {
        cnt[i] += cnt[i - 1];
    }
    for(int i=n-1;i>=0;--i)
    {
        sa[--cnt[x[i]]] = i;
    }
    int k = 0;
    for(int step=1;k<n;step<<=1)
    {
        k = 0;
        for(int i=n-step;i<n;++i)
        {
            y[k ++] = i;
        }
        for(int i=0;i<n;++i)
        {
            if(sa[i] >= step)
            {
                y[k ++] = sa[i] - step;
            }
        }
        for(int i=0;i<m;++i)
        {
            cnt[i] = 0;
        }
        for(int i=0;i<n;++i)
        {
            ++ cnt[x[y[i]]];
        }
        for(int i=0;i<m;++i)
        {
            cnt[i] += cnt[i - 1];
        }
        for(int i=n-1;i>=0;--i)
        {
            sa[-- cnt[x[y[i]]]] = y[i];
        }
        k = 1;
        y[sa[0]] = 0;
        for(int i=1;i<n;++i)
        {
            if(isRankSame(x, sa[i], sa[i - 1], step))
            {
                y[sa[i]] = k - 1;
            }
            else
            {
                y[sa[i]] = k ++;
            }
        }
        t = x, x = y, y = t;
        m = k;
    }
}

void calcLCP(int a[], int n)
{
    for(int i=1;i<=n;++i)
    {
        rank[sa[i]] = i;
    }
    int k = 0;
    for(int i=0;i<n;++i)
    {
        if(k)
        {
            -- k;
        }
        int j = sa[rank[i] - 1];
        while(a[i + k] == a[j + k])
        {
            ++ k;
        }
        lcp[rank[i]] = k;
    }
}

int n, k;
int a[MAXN];

bool judge(int len)
{
    int num = 0;
    for(int i=1;i<=n;++i)
    {
        if(lcp[i] < len)
        {
            num = 0;
        }
        else
        {
            if(++ num >= k - 1)
            {
                return true;
            }
        }
    }
    return false;
}

int solve()
{
    int ans = 0;
    int l = 0, r = n;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(judge(mid))
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        a[n] = 0;
        calcSA(a, n + 1, MAXM);
        calcLCP(a, n);
        printf("%d\n", solve());
    }
    return 0;
}
