//#define METHOD_MANACHER
#define METHOD_SUFFIX_ARRAY

#ifdef METHOD_MANACHER
#include <cstdio>
#include <cstring>
const int MAXN = 2000100;
char s[MAXN];
int p[MAXN];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int caseNumber = 0;
	while(scanf("%s", s), strcmp(s, "END"))
	{
	    int len = strlen(s);
	    s[(len<<1)+2] = 0;
	    for(int i=len-1;i>=0;--i)
	    {
	        s[(i<<1)+3] = '#';
	        s[(i<<1)+2] = s[i];
	    }
	    s[0] = '$', s[1] = '#';
	    len = (len<<1) + 2;
	    printf("Case %d: ", ++ caseNumber);
	    int mx = 0, id, ans = -1;
	    for(int i=0;i<len;++i)
	    {
	        if(mx > i)
	        {
	            p[i] = min(p[(id<<1)-i], mx-i);
	        }
	        else
	        {
	            p[i] = 1;
	        }
	        for(;s[i-p[i]]==s[i+p[i]];++p[i]);
	        if(p[i] + i > mx)
	        {
	            mx = p[i] + i;
	            id = i;
	        }
	        ans = max(ans, p[i]);
	    }
	    printf("%d\n", ans - 1);
	}
    return 0;
}
#endif

#ifdef METHOD_SUFFIX_ARRAY
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000005;
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

int n;
char s[MAXN];
int a[MAXN];

int solve()
{
    int ans = 1;
    calcSA(a, n + 1, MAXM);
    calcLCP(a, n);
    for(int i=1;i<=n;++i)
    {
        ans = max(ans, lcp[i]);
    }
    return ans;
}

int main()
{
    int t = 0;
    while(~scanf("%s", s), strcmp(s, "END"))
    {
        n = strlen(s);
        for(int i=0;i<n;++i)
        {
            a[i] = s[i];
        }
        a[n] = '#';
        for(int i = n * 2, j = 0;j < n;-- i, ++ j)
        {
            a[i] = a[j];
        }
        n = n * 2 + 1;
        a[n] = 0;
        printf("Case %d: %d\n", ++ t, solve());
    }
    return 0;
}

#endif
