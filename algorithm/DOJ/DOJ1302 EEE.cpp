#include <cstdio>
#include <cstring>
const int MAXN = 100005;
const int MAXM = MAXN * 2;

int n, q;
char s[MAXN];
int sum;
int count[MAXN * 3];
int total[MAXN];

int main()
{
    int a, b;
    while(~scanf("%d", &n))
    {
        scanf("%s", s + 1);
        memset(count, 0, sizeof(count));
        count[MAXM] = 1;
        sum = 0;
        for(int i=1;i<=n;++i)
        {
            if(s[i] == '0')
            {
                sum += 1;
            }
            else
            {
                sum -= 2;
            }
            total[i] = count[sum + MAXM] ++;
        }
        for(int i=1;i<=n;++i)
        {
            total[i] += total[i - 1];
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &a, &b);
            printf("%d\n", total[b] - total[a - 1]);
        }
    }
    return 0;
}
