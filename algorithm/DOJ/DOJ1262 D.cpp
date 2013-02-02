#include <cstdio>
#include <cstring>

bool ip[32000];
long long p[32000];
int pn;

void in()
{
    memset(ip, true, sizeof(ip));
    for(int i=4;i<32000;i+=2)
    {
        ip[i] = false;
    }
    for(int i=3;i<32000;i+=2)
    {
        for(int j=3;i*j<32000;j+=2)
        {
            ip[i*j] = false;
        }
    } pn = 0;
    for(int i=2;i<32000;++i)
    {
        if(ip[i])
        {
            p[pn++] = i;
        }
    }
}

int r[10000], rd[10000];
int rn;

void di(int x)
{
    rn = 0;
    for(int i=0;i<pn;++i)
    {
        if(x % p[i] == 0)
        {
            r[rn] = p[i];
            rd[rn] = 0;
            while(x % p[i] == 0)
            {
                x /= p[i];
                ++ rd[rn];
            }
            ++rn;
        }
        if(x == 1)
        {
            break;
        }
    }
    if(x != 1)
    {
        r[rn] = x;
        rd[rn] = 1;
        ++ rn;
    }
    for(int i=0;i<rn;++i)
    {
        rd[i] = rd[i] * 2;
    }
}

int a, c, xx;

void d(int x, long long t)
{
    if(x == rn)
    {
        if((long long)xx * xx / t > a)
        {
            ++ c;
        }
        return;
    }
    for(int i=0;i<=rd[x];++i)
    {
        d(x + 1, t);
        t = t * r[x];
    }
}

int main()
{
    in();
    while(scanf("%d%d", &a, &xx) != EOF)
    {
        di(xx);
        c = 0;
        d(0, 1);
        printf("%d\n", c);
    }
    return 0;
}
