#include <cstdio>

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m), n || m)
    {
        printf("%d\n", m & 1);
    }
    return 0;
}
