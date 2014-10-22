#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXM = 1005;
const int INF = 1000000000;

int n, m;
int l[MAXN][MAXN], r[MAXN][MAXN];

struct Node
{
    int pos, num;
}a[MAXN], b[MAXN];
int aNum, bNum;
int ans1, ans2;

bool compare1(const Node &a, const Node &b)
{
    return a.pos < b.pos;
}

bool compare2(const Node &a, const Node &b)
{
    return a.pos > b.pos;
}

void solve()
{
    sort(a + 1, a + aNum + 1, compare1);
    sort(b + 1, b + bNum + 1, compare2);
    int m = max(aNum, bNum);
    for(int i=0;i<=m;++i)
    {
        for(int j=0;j<=n+1;++j)
        {
            l[i][j] = r[i][j] = INF;
        }
    }
    l[0][0] = r[0][n + 1] = 0;
    for(int i=1;i<=aNum;++i)
    {
        for(int j=0;j<=a[i].pos;++j)
        {
            l[i][j] = l[i-1][j];
            if(j >= a[i].num)
            {
                l[i][j] = min(l[i][j], l[i-1][j - a[i].num] + 1);
            }
        }
    }
    for(int i=1;i<=bNum;++i)
    {
        for(int j=n+1;j>=b[i].pos;--j)
        {
            r[i][j] = r[i-1][j];
            if(j + b[i].num <= n + 1)
            {
                r[i][j] = min(r[i][j], r[i-1][j + b[i].num] + 1);
            }
        }
    }
    ans1 = 0;
    ans2 = INF;
    for(int i=n;i>=0;--i)
    {
        if(l[aNum][i] < INF || r[bNum][n - i + 1] < INF)
        {
            ans1 = i;
            break;
        }
        for(int j=1;j<i;++j)
        {
            if(l[aNum][j] <INF && r[bNum][n - (i - j) + 1] < INF)
            {
                ans1 = i;
                break;
            }
        }
        if(ans1 != 0)
        {
            break;
        }
    }
    for (int i=0;i<=ans1;++i)
    {
        if (l[aNum][i] < INF && r[bNum][n - (ans1 - i) + 1] < INF)
        {
            ans2 = min(ans2, l[aNum][i] + r[bNum][n - (ans1 - i) + 1]);
        }
    }
    if(ans2 == INF)
    {
        ans2 = 0;
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    int x, y, z;
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d", &n, &m);
        aNum = bNum = 0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            if(x == 1)
            {
                a[++aNum].pos = y;
                a[aNum].num = z;
            }
            else
            {
                b[++bNum].pos = y;
                b[bNum].num = z;
            }
        }
        solve();
        printf("Case %d: %d %d\n", cas, ans1, ans2);
    }
}
