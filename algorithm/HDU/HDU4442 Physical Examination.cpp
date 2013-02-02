#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MOD = 365 * 24 * 60 * 60;

struct Node
{
    int a, b;
} node[MAXN];

bool operator < (const Node &a, const Node &b)
{
    return 1LL * a.a * b.b < 1LL * a.b * b.a;
}

int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &node[i].a, &node[i].b);
        }
        sort(node, node + n);
        long long time = 0;
        long long count = 0;
        for(int i=0;i<n;++i)
        {
            count += node[i].a + time * node[i].b;
            time += node[i].a + time * node[i].b;
            count %= MOD;
            time %= MOD;
        }
        cout << count << endl;
    }
    return 0;
}
