#include <cstdio>

int main()
{
    int n, a;
    while (scanf("%d", &n), n)
    {
        int sg = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            sg ^= a;
        }
        puts(sg ? "Rabbit Win!" : "Grass Win!");
    }
    return 0;
}
