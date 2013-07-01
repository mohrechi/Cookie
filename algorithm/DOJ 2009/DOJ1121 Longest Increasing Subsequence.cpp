#include <cstdio>
static const int MAXN = 1001;
int a[MAXN];
int dp[MAXN];
int cnt[MAXN];

int main()
{
    int n;
    int max, pos;
    bool flag;
    while(~scanf("%d",&n))
    {
        max = 0;
        pos = 0;
        flag = false;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            dp[i] = 1;
            cnt[i] = 1;
            for(int j=0;j<i;++j)
            {
                if(a[i] >= a[j])
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                    {
                        ++ cnt[i];
                    }
                }
            }
            if(dp[i] > max)
            {
                max = dp[i];
                pos = i;
                flag = false;
            }
            else if(dp[i] == max)
            {
                flag = true;
            }
        }
        if(cnt[pos] == 1 && !flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

/*#include <stdio.h>
#include <memory>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>
#include <time.h>
#include <limits>
using namespace std;
#define N 10005
//#define MOD 1000000000
#define MOD 0X3FFFFFFFFFFFFFFFLL
#define nType int
//#define vType int
#define vType long long
#define typev vType

struct node
{
    nType val;
    int len;
    node(nType _val=0, int _len=0) : val(_val), len(_len) {}
    void set(nType _val, int _len)
    {
        val = _val;
        len = _len;
    }
    bool operator < (const node& tn) const
    {
        return len < tn.len || (len == tn.len && val < tn.val);
    }
    bool operator == (const node& tn) const
    {
        return len == tn.len && val == tn.val;
    }
}nodes[N];
nType in[N], ks[N];
vType num[N];
int dp[N], lId[N], rId[N];
int n, k, maxLen;
typev ar[N];
int vMax;
int lowb(int t)
{
    return t & (-t);
}

void add(int i, typev v)
{
    for(; i < vMax; i += lowb(i))
    {
        ar[i] = (ar[i]+v)%MOD;
    }
}

typev sum(int i)
{
    typev s = 0;
    for(; i > 0; i -= lowb(i))
    {
    s = (s+ar[i])%MOD;
    }
    return s;
}

bool input()
{
    if(scanf("%d", &n) == EOF) return false;
    int i;
    for(i = 0; i < n; i++)
    {
    scanf("%d", in+i);
    }
    return true;
}

int getPos(const int& key)
{
    int l, r, mid;
    l = 0;
    r = k - 1;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(ks[mid] >= key) r = mid-1;
        else l = mid+1;
    }
    return r+1;
}

int getLast(int l, int r, const int& key)
{
    int mid;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if(nodes[mid].val < key) l = mid+1;
        else r = mid-1;
    }
    return l-1;
}

void solve()
{
    int i, cnt, tl, tr;
    k = 0;
    ks[k++] = in[0];
    dp[0] = k;
    nodes[0].set(in[0], 1);
    for(i = 1; i < n; i++)
    {
        if(in[i] > ks[k-1])
        {
            ks[k++] = in[i];
            dp[i] = k;
        }
        else
        {
            ks[dp[i] = getPos(in[i])] = in[i];
            dp[i]++;
        }
        nodes[i].set(in[i], dp[i]);
    }
    maxLen = k;
    sort(nodes, nodes+n);
    for(i = cnt = 1; i < n; i++)
    {
        if(nodes[i] == nodes[cnt-1]) continue;
        nodes[cnt++] = nodes[i];
    }
    for(lId[1] = 0, i = 1; i < cnt; i++)
    {
        if(nodes[i].len == nodes[i-1].len) continue;
        rId[nodes[i-1].len] = i-1;
        lId[nodes[i].len] = i;
    }
    rId[nodes[cnt-1].len] = cnt-1;
    vMax = cnt+1;
    for(i = 0; i < vMax; i++)
    {
        ar[i] = 0;
    }
    vType ans = 0;
    for(i = 0; i < n; i++)
    {
        if(dp[i] == 1)
        {
            num[i] = 1;
        }
        else
        {
            tl = lId[dp[i]-1];
            tr = rId[dp[i]-1];
            tr = getLast(tl, tr, in[i]);
            num[i] = (sum(tr+1)-sum(tl)+MOD)%MOD;
        }
        tl = lId[dp[i]];
        tr = rId[dp[i]];
        tr = getLast(tl, tr, in[i]);
        tr+=2;
        add(tr, num[i]);
        if(dp[i] == maxLen)
        {
        ans = (ans + num[i]) % MOD;
        }
    }
    if(ans == 1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
int main()
{
    while(input()) solve();
    return 0;
}*/
