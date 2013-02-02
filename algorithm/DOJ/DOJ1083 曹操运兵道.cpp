#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Matrix
{
    long long data[2][2];
    Matrix(long long d11, long long d12, long long d21, long long d22)
    {
        data[0][0] = d11;
        data[0][1] = d12;
        data[1][0] = d21;
        data[1][1] = d22;
    }
};

inline Matrix operator * (const Matrix &a, const Matrix &b)
{
    Matrix c(0, 0, 0, 0);
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
                c.data[i][j] %= MOD;
            }
        }
    }
    return c;
}

int main()
{
    long long n;
    while(scanf("%lld", &n), n + 1)
    {
        Matrix mat(24, 8, 64, 24);
        Matrix res(1, 0, 0, 1);
        for(int i = 0; (1LL << i) <= n; ++i)
        {
            if(n & (1LL << i))
            {
                res = res * mat;
            }
            mat = mat * mat;
        }
        printf("%lld\n", res.data[1][1]);
    }
    return 0;
}
