#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Matrix
{
    long long data[3][3];
    inline void output()
    {
        printf("Matrix: \n");
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                printf("%lld\t", data[i][j]);
            }
            printf("\n");
        }
    }
};

Matrix operator *(const Matrix &a, const Matrix &b)
{
    Matrix c;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            c.data[i][j] = 0;
            for (int k = 0; k < 3; ++k)
            {
                c.data[i][j] = (c.data[i][j] + (a.data[i][k] * b.data[k][j]) % MOD) % MOD;
                c.data[i][j] = (c.data[i][j] + MOD) % MOD;
            }
        }
    }
    return c;
}

long long get(long long x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 2;
    }
    if (x == 2)
    {
        return 4;
    }
    if (x == 3)
    {
        return 7;
    }
    Matrix fact;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            fact.data[i][j] = 0;
        }
    }
    fact.data[0][0] = 2;
    fact.data[2][0] = -1;
    fact.data[0][1] = 1;
    fact.data[1][2] = 1;
    Matrix mat;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            mat.data[i][j] = 0.0;
        }
        mat.data[i][i] = 1.0;
    }
    for (long long i = 0; (1 << i) <= x; ++i)
    {
        if (x & (1 << i))
        {
            mat = mat * fact;
        }
        fact = fact * fact;
    }
    return mat.data[0][0];
}

int main()
{
    long long a, b;
    while (~scanf("%lld%lld", &a, &b))
    {
        ++a, ++b;
        printf("%lld\n", (get(b) - get(a - 1) + MOD) % MOD);
    }
    return 0;
}
