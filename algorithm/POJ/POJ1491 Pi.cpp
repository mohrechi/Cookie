#include <cstdio>
#include <cmath>

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    return gcd(b, a%b);
}

int main(int argc, char *argv[])
{
    int n, a[55], c;
    while(scanf("%d",&n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
        }
        c = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(gcd(a[j], a[i]) == 1)
                {
                    ++c;
                }
            }
        }
        if(c)
        {
            printf("%.6f\n",sqrt(3.0 * n*(n-1) /c));
        }
        else
        {
            printf("No estimate for this data set.\n");
        }
    }
    return 0;
}
