#include <cstdio>
#include <cstring>
const int MAXN = 1005;

int n, q;
int m[MAXN], d[MAXN];
int h[MAXN], c[MAXN];

int main()
{
    int t;
    while(~scanf("%d%d", &n, &t))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &m[i], &d[i]);
            h[i] = t;
        }
        scanf("%d", &q);
        int last = n;
        memset(c, 0, sizeof(c));
        for(int k=0;k<q;++k)
        {
            if(k)
                printf(" ");
            int max = -1, p;
            for(int i=0;i<n;++i)
            {
                if(h[i] > max)
                {
                    max = h[i];
                    p = i;
                }
            }
            for(int i=0;i<n;++i)
                ++ c[i];
            if(p != last)
            {
                c[last] = 1, c[p] = 1;
            }
            for(int i=0;i<n;++i)
                if(i == p)
                    h[i] -= d[i] * c[i];
                else
                    h[i] += m[i] * c[i];
            last = p;
            printf("%d", last + 1);
        }
        printf("\n");
    }
    return 0;
}
