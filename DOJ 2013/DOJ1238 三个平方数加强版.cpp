#include <cstdio>
const int MAXN = 1000000 + 10;

bool visit[MAXN];
int sum[MAXN];

int main()
{
    int t, n;
    for (int i = 0; i * i <= MAXN; ++i)
    {
        for (int j = i; i * i + j * j <= MAXN; ++j)
        {
            for (int k = j; i * i + j * j + k * k <= MAXN; ++k)
            {
                visit[i * i + j * j + k * k] = true;
            }
        }
    }
    for (int i = 1; i <= MAXN; ++i)
    {
        sum[i] = sum[i - 1] + 1 - visit[i];
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%d\n", sum[n]);
    }
    return 0;
}
