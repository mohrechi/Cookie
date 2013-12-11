#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2005;

long long n, cm;
struct Item
{
    long long c, v;
    void input()
    {
        scanf("%lld%lld", &c, &v);
    }
    bool operator <(const Item &item) const
    {
        return c > item.c;
    }
} item[MAXN];
long long sum, ans;
long long rValSum[MAXN];

void dfs(int index, long long cost, long long value)
{
    if (value + rValSum[index] <= ans)
    {
        return;
    }
    ans = max(ans, value);
    if (index == n)
    {
        return;
    }
    if (cost + item[index].c <= cm)
    {
        dfs(index + 1, cost + item[index].c, value + item[index].v);
    }
    dfs(index + 1, cost, value);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld%lld", &n, &cm);
        for (int i = 0; i < n; ++i)
        {
            item[i].input();
        }
        sort(item, item + n);
        sum = 0;
        long long costSum = 0;
        long long valueSum = 0;
        for (int i = 0; i < n; ++i)
        {
            if (item[i].c == 0)
            {
                for (int j = i; j < n; ++j)
                {
                    sum += item[j].v;
                }
                n = i;
                break;
            }
            costSum += item[i].c;
            valueSum += item[i].v;
        }
        rValSum[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            rValSum[i] = rValSum[i + 1] + item[i].v;
        }
        ans = 0;
        if (costSum > cm)
        {
            dfs(0, 0, 0);
        }
        else
        {
            ans = valueSum;
        }
        printf("%lld\n", sum + ans);
    }
    return 0;
}
