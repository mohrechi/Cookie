#include <cstdio>
const int MAXN = 1000 + 10;

int n, q;
bool mat[MAXN];

int main()
{
    int o, p, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &o);
            if (i == j)
            {
                cnt += o;
                mat[i] = o;
            }
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &o);
        switch (o)
        {
        case 1:
        case 2:
            scanf("%d", &p);
            cnt -= mat[p];
            mat[p] ^= 1;
            cnt += mat[p];
            break;
        case 3:
            printf("%d", cnt & 1);
            break;
        }
    }
    putchar('\n');
    return 0;
}
