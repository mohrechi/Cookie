#include <cstdio>

int main()
{
    int n, k, a;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    while (n--)
    {
        scanf("%d", &a);
        cnt += 5 - a >= k;
    }
    printf("%d\n", cnt / 3);
    return 0;
}
