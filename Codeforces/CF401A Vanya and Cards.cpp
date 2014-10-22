#include <cstdio>

int main()
{
    int n, m, a, sum;
    scanf("%d%d", &n, &m);
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        sum += a;
    }
    sum = sum >= 0 ? sum : -sum;
    printf("%d\n", (sum + m - 1) / m);
    return 0;
}
