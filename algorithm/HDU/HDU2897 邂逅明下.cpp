#include <cstdio>

int main()
{
    int n, p, q;
    while (~scanf("%d%d%d", &n, &p, &q))
    {
        int k = n % (p + q);
        puts(k == 0 || k > p ? "WIN" : "LOST");
    }
    return 0;
}
