#include<cstdio>

int main()
{
    int t, s, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &s, &k);
        printf("%d\n", k % 2 == 0 && s % (k + 1) == k ? k : s % (k + 1) % 2);
    }
    return 0;
}
