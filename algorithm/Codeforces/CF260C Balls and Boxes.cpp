#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int INF = 2100000000;

int n, k;
long long a[MAXN];

struct TreeNode
{
    int l, r;
    long long mini;
} tree[MAXN * 3];

long long build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if(l == r)
    {
        return tree[x].mini = a[l];
    }
    int mid = (l + r) >> 1;
    tree[x].mini = min(build(x << 1, l, mid), build((x << 1) + 1, mid + 1, r));
}

long long query(int x, int l, int r)
{
    if(l > r)
    {
        return INF;
    }
    if(tree[x].l == l && tree[x].r == r)
    {
        return tree[x].mini;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        return query(x << 1, l, r);
    }
    if(l > mid)
    {
        return query((x << 1) + 1, l, r);
    }
    return min(query(x << 1, l, mid), query((x << 1) + 1, mid + 1, r));
}

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d", &a[i]);
        }
        build(1, 1, n);
        int mini[2], miniNum = 0;
        for(int i=1;i<=n;++i)
        {
            if(i < k)
            {
                if(query(1, i + 1, k) >= a[i] + 1)
                {
                    if(min(query(1, 1, i), query(1, k + 1, n)) >= a[i])
                    {
                        long long sum = a[i];
                        for(int j=1;j<i;++j)
                        {
                            a[j] -= a[i];
                            sum += a[i];
                        }
                        for(int j=i+1;j<=k;++j)
                        {
                            a[j] -= a[i] + 1;
                            sum += a[i] + 1;
                        }
                        for(int j=k+1;j<=n;++j)
                        {
                            a[j] -= a[i];
                            sum += a[i];
                        }
                        a[i] = sum;
                        break;
                    }
                }
            }
            else if(i > k)
            {
                if(query(1, k + 1, i) >= a[i])
                {
                    if(min(query(1, 1, k), query(1, i + 1, n)) >= a[i] + 1)
                    {
                        long long sum = a[i];
                        for(int j=1;j<=k;++j)
                        {
                            a[j] -= a[i] + 1;
                            sum += a[i] + 1;
                        }
                        for(int j=k+1;j<i;++j)
                        {
                            a[j] -= a[i];
                            sum += a[i];
                        }
                        for(int j=i+1;j<=n;++j)
                        {
                            a[j] -= a[i] + 1;
                            sum += a[i] + 1;
                        }
                        a[i] = sum;
                        break;
                    }
                }
            }
            else
            {
                if(query(1, 1, n) >= a[i])
                {
                    long long sum = a[i];
                    for(int j=1;j<i;++j)
                    {
                        a[j] -= a[i];
                        sum += a[i];
                    }
                    for(int j=i+1;j<=n;++j)
                    {
                        a[j] -= a[i];
                        sum += a[i];
                    }
                    a[i] = sum;
                    break;
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            printf("%I64d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
