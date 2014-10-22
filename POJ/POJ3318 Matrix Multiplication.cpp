#include <cstdio>
#include <cstring>
static const int MAXN = 505;

int n;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int x[MAXN], d[MAXN], e[MAXN], f[MAXN];

inline void readMatrix(int m[][MAXN])
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d", &m[i][j]);
}

inline void mutiply(int m1[], int m2[][MAXN], int r[])
{
    for(int i=0;i<n;++i)
        r[i] = 0;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            r[i] += m1[j] * m2[j][i];
}

inline bool equal(int m1[], int m2[])
{
    for(int i=0;i<n;++i)
        if(m1[i] != m2[i])
            return false;
    return true;
}

int main()
{
    while(~scanf("%d", &n))
    {
        readMatrix(a);
        readMatrix(b);
        readMatrix(c);
        for(int i=0;i<n;++i)
            x[i] = i;
        mutiply(x, a, d);
        mutiply(d, b, e);
        mutiply(x, c, f);
        if(equal(e, f))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
