#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Matrix
{
    long long data[2][2];

    void clear()
    {
        for(int i=0;i<2;++i)
        {
            for(int j=0;j<2;++j)
            {
                data[i][j] = 0.0;
            }
        }
    }
};

long long m, a, c, A0, An, n;

Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            c.data[i][j] = 0.0;
            for(int k=0;k<2;++k)
            {
                c.data[i][j] += (a.data[i][k] * b.data[k][j]) % m;
                c.data[i][j] %= m;
            }
        }
    }
    return c;
}

int main()
{
    while(~scanf("%lld%lld%lld%lld%lld", &m, &a, &c, &A0, &n))
    {
        Matrix world;
        world.data[0][0] = 1; world.data[0][1] = 0;
        world.data[1][0] = 0; world.data[1][1] = 1;
        Matrix quick;
        quick.data[0][0] = a; quick.data[0][1] = 0;
        quick.data[1][0] = c; quick.data[1][1] = 1;
        for(int i=0;(1<<i)<=n;++i)
        {
            if(n & (1 << i))
            {
                world = world * quick;
            }
            quick = quick * quick;
        }
        An = ((A0 * world.data[0][0]) % m + world.data[1][0]) % m;
        printf("%lld\n", An);
    }
    return 0;
}
