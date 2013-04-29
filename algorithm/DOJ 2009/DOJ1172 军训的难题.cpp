#include <cstdio>
#include <cstring>
const int MAXN = 21;
int a[MAXN], b[MAXN];

inline int c(int b, int a)
{
    if(a > (b>>1))
    {
        a = b - a;
    }
    if(a == 0) return 1;
    long long res = 1;
    for(int i=0;i<a;++i)
    {
        res *= b - i;
    }
    for(int i=1;i<=a;++i)
    {
        res /= i;
    }
    return (int)res;
}

int main()
{
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for(int i=3;i<=20;++i)
    {
        for(int j=1;j<=i-2;++j)
        {
            a[i] += c(i-1, j);
        }
    }
    for(int i=3;i<=20;++i)
    {
        for(int j=3;j<=i;++j)
        {
            b[i] += a[j] * c(i, j);
        }
    }
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", b[n]);
    }
    return 0;
}
