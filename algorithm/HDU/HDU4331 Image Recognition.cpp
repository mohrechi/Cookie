#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int n;
bool g[MAXN][MAXN];
int l[MAXN][MAXN], r[MAXN][MAXN];
int u[MAXN][MAXN], d[MAXN][MAXN];
int c[MAXN], clen;

struct Node
{
    int value;
    int index;
    bool operator < (const Node &node) const
    {
        return value < node.value;
    }
}a[MAXN];

struct Seg
{
    int left, right;
}s[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    while(x <= clen)
    {
        ++ c[x];
        x += lowbit(x);
    }
}

int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -=  lowbit(x);
    }
    return sum;
}

int getAnsAt(int x, int y)
{
    int ans = 0;
    int len = min(n - x, n - y);
    int snum = 0;
    for(int i=0;i<len;++i)
    {
        a[i].value = i - min(l[x+i][y+i], u[x+i][y+i]) + 1;
        a[i].index = i;
        if(g[x+i][y+i])
        {
            s[snum].left = i;
            s[snum].right = i + min(r[x+i][y+i], d[x+i][y+i]) - 1;
            ++ snum;
        }
    }
    sort(a, a + len);
    int aindex = 0;
    memset(c, 0, sizeof(c));
    clen = len;
    for(int i=0;i<snum;++i)
    {
        while(s[i].left >= a[aindex].value && aindex < len)
        {
            update(a[aindex].index + 1);
            ++ aindex;
        }
        ans += query(s[i].right + 1) - query(s[i].left);
    }
    return ans;
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &g[i][j]);
            }
        }
        for(int i=0;i<n;++i)
        {
            l[i][0] = g[i][0];
            u[0][i] = g[0][i];
            for(int j=1;j<n;++j)
            {
                if(g[i][j])
                {
                    l[i][j] = l[i][j-1] + 1;
                }
                else
                {
                    l[i][j] = 0;
                }
                if(g[j][i])
                {
                    u[j][i] = u[j-1][i] + 1;
                }
                else
                {
                    u[j][i] = 0;
                }
            }
            r[i][n-1] = g[i][n-1];
            d[n-1][i] = g[n-1][i];
            for(int j=n-2;j>=0;--j)
            {
                if(g[i][j])
                {
                    r[i][j] = r[i][j+1] + 1;
                }
                else
                {
                    r[i][j] = 0;
                }
                if(g[j][i])
                {
                    d[j][i] = d[j+1][i] + 1;
                }
                else
                {
                    d[j][i] = 0;
                }
            }
        }
        int ans = getAnsAt(0, 0);
        for(int i=1;i<n;++i)
        {
            ans += getAnsAt(0, i);
            ans += getAnsAt(i, 0);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}
