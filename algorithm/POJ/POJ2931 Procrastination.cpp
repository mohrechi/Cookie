#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int t[55], a[3];

long long surrealNumber(int T[], int n)
{
    long long x = 0, k = 1;
    int i = 1;
    k <<= 52;
    while (i <= n && T[i] == T[1])
    {
        if (T[i] == 'W')
        {
            x += k;
        }
        else
        {
            x -= k;
        }
        ++i;
    }
    k >>= 1;
    while (i <= n)
    {
        if (T[i] == 'W')
        {
            x += k;
        }
        else
        {
            x-=k;
        }
        ++i;
        k >>= 1;
    }
    return x;
}

int main()
{
    int cas,s1;
    char s[10], tmp[4];
    scanf("%d", &cas);
    while (cas--)
    {
        long long c1 = 0, c2 = 0;
        scanf("%s%d", s, &s1);
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 1; j <= a[i]; ++j)
            {
                scanf("%s", tmp);
                t[j] = tmp[0];
            }
            c1 += surrealNumber(t, a[i]);
        }
        for (int i = 0; i < 3; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 3; ++i)
        {
            for(int j=1; j<=a[i]; ++j)
            {
                scanf("%s", tmp);
                t[j] = tmp[0];
            }
            c2 += surrealNumber(t, a[i]);
        }
        printf("%s %d: %s\n", s, s1, c1 >= c2 ? "Yes" : "No");
    }
    return 0;
}
