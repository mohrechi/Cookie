#include <cstdio>
#include <cstring>
const int MAXN = 4096;

int a[2][MAXN], f[2], r[2];
int s[MAXN], t;

int main()
{
    int n;
    while(~scanf("%d%d%d", &r[0], &r[1], &n))
    {
        for(int i=0;i<r[0];++i) scanf("%d", &a[0][i]);
        for(int i=0;i<r[1];++i) scanf("%d", &a[1][i]);
        if(r[0] == 0 || r[1] == 0)
        {
            printf("%d %d\n", r[0], r[1]);
            continue;
        }
        bool p = false;
        t = 0;
        f[0] = f[1] = 0;
        while(n--)
        {
            s[t++] = a[p][f[p]++];
            for(int i=t-2;i>=0;--i)
                if(s[i] == s[t - 1])
                {
                    while(t != i)
                        a[p][r[p]++] = s[--t];
                    break;
                }
            if(f[p] == r[p])
                break;
            p = !p;
        }
        printf("%d %d\n", r[0] - f[0], r[1] - f[1]);
    }
    return 0;
}
