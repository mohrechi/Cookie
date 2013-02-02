#include <cstdio>
#include <cstring>
static const int MAXN = 105;

int n;
int c[MAXN], v[MAXN], w;

int main()
{
    double max;
    int pos;
    while(scanf("%d", &n), n)
    {
        max = 0.0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&v[i]);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&c[i]);
            if(max < (double)v[i] / c[i])
            {
                max = (double) v[i] / c[i];
                pos = i;
            }
        }
        scanf("%d", &w);
        printf("%.4lf\n", (double)w / c[pos] * v[pos]);
    }
    return 0;
}
