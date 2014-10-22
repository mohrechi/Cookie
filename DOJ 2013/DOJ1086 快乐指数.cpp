#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
const int MAXM = MAXN * 2 + 5;

int n, m;
int num[MAXM];

int main()
{
    int q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &q);
        ++num[q + MAXN];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &q);
        printf("%d\n", num[q + MAXN]);
    }
    return 0;
}
