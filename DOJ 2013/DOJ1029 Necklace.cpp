#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 50005
#define MAXM 200005
#define INF 100000000
#define L(X) X<<1
#define R(X) X<<1|1
using namespace std;
struct interval
{
    int l, r, id;
    bool operator <(const interval &a)const
    {
        return r < a.r;
    }
}p[MAXM];
int x[MAXN], a[MAXN], h[MAXN], n;
int tx[MAXN], ans[MAXM];

int bin(int v, int bound)
{
    int low = 0, high = bound - 1;
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(x[mid] == v) return mid;
        if(x[mid] < v) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int lowbit(int x)
{
    return x & -x;
}

void modify(int x, int v)
{
    for(int i = x; i <= n; i += lowbit(i))
        tx[i] += v;
}

int get_sum(int x)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
    sum += tx[i];
    return sum;
}

int main()
{
    int m;
    while(~scanf("%d", &n))
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            x[cnt++] = a[i];
        }
        memset(tx, 0, sizeof(tx));
        sort(x, x + cnt);
        cnt = unique(x, x + cnt) - x;
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &p[i].l, &p[i].r);
            p[i].id = i;
        }
        sort(p, p + m);
        for(int i = 0; i < cnt; i++)
            h[i] = 0;
        int j = 0;
        for(int i = 1; i <= n; i++)
        {
            int id = bin(a[i], cnt);
            if(h[id]) modify(h[id], -1);
            modify(i, 1);
            h[id] = i;
            for(; j < m; j++)
            {
                if(p[j].r == i) ans[p[j].id] = get_sum(p[j].r) - get_sum(p[j].l - 1);
                else break;
            }
        }
        for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    }
    return 0;
}
