#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
const int MAXM = 255;

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

int n, n1, n2, a[MAXN];
char s1[MAXN], s2[MAXN];

int solve()
{
    int ans = 0;
    calcSA(a, n + 1, MAXM);
    calcLCP(a, n);
    for(int i=1;i<=n;++i)
    {
        if(lcp[i] > ans)
        {
            if(sa[i] < n1 && sa[i - 1] > n1)
            {
                ans = lcp[i];
            }
            if(sa[i] > n1 && sa[i - 1] < n1)
            {
                ans = lcp[i];
            }
        }
    }
    return ans;
}

int main()
{
    while(~scanf("%s%s", &s1, &s2))
    {
        n = 0;
        for(n1=0;s1[n1];++n1)
        {
            a[n++] = s1[n1];
        }
        a[n++] = ' ';
        for(n2=0;s2[n2];++n2)
        {
            a[n++] = s2[n2];
        }
        a[n] = 0;
        printf("%d\n", solve());
    }
    return 0;
}
