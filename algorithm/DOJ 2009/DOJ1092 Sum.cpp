#include <cstdio>
int a[50005];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int z = 0, m = -50000;
        long long s = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
            if(a[i]>0)
            {
                s += a[i];
            }
            else if(a[i] == 0)
            {
                ++z;
            }
            else
            {
                if(a[i] > m)
                {
                    m = a[i];
                }
            }
        }
        if(s>0)
        {
            long long r = 1;
            for(int i=0;i<z;++i)
            {
                r = (r<<1) % 1000000009;
            }
            printf("%lld %lld\n",s,r);
        }
        else
        {
            if(z>0)
            {
                long long r = 1;
                for(int i=0;i<z;++i)
                {
                    r = (r<<1) % 1000000009;
                }
                r = (r + 1000000008) % 1000000009;
                printf("0 %lld\n",r);
            }
            else
            {
                int c = 0;
                for(int i=0;i<n;++i)
                {
                    if(a[i] == m)
                    {
                        ++c;
                    }
                }
                printf("%d %d\n",m,c);
            }
        }
    }
    return 0;
}
