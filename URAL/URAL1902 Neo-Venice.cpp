#include <cstdio>

int main()
{
    int n, t, s, a;
    scanf("%d%d%d", &n, &t, &s);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        printf("%.6f\n", (s + t + a) * 0.5);
    }
    return 0;
}
