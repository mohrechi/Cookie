#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000001;

bool isPrime[MAXN];
int prime[MAXN], primeNum;

char num[MAXN];

struct Node
{
    int pos, k, index;
    bool start;
    bool operator <(const Node &node) const
    {
        return pos < node.pos;
    }
} node[50000];
int ans[50000], nodeNum;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXN; i += 2)
    {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXN; i += 2)
    {
        for (int j = 3; i * j < MAXN; j += 2)
        {
            isPrime[i * j] = false;
        }
    }
    for (int i = 2; i < MAXN; ++i)
    {
        if (isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
    for (int i = 0; i < primeNum; ++i)
    {
        for (int j = prime[i]; j < MAXN; j += prime[i])
        {
            ++num[j];
        }
    }
}

int main()
{
    int T, a, b, k;
    init();
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%d%d%d", &a, &b, &k);
        node[nodeNum].pos = a - 1;
        node[nodeNum].start = true;
        node[nodeNum].k = k;
        node[nodeNum++].index = t;
        node[nodeNum].pos = b;
        node[nodeNum].start = false;
        node[nodeNum].k = k;
        node[nodeNum++].index = t;
    }
    sort(node, node + nodeNum);
    int sum[100], index = 0;
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i < MAXN; ++i)
    {
        ++sum[num[i]];
        while (index < nodeNum && node[index].pos == i)
        {
            if (node[index].start)
            {
                ans[node[index].index] -= sum[node[index].k];
            }
            else
            {
                ans[node[index].index] += sum[node[index].k];
            }
            ++index;
        }
    }
    for (int t = 0; t < T; ++t)
    {
        printf("%d\n", ans[t]);
    }
    return 0;
}
