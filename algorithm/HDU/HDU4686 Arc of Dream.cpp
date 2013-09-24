#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

struct Matrix
{
    long long x[5][5];
    Matrix()
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                x[i][j] = 0;
            }
        }
    }
    void output()
    {
        printf("Matrix: \n");
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                printf("%I64d\t", x[i][j]);
            }
            printf("\n");
        }
    }
};

Matrix operator *(const Matrix &a, const Matrix &b)
{
    Matrix c;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                c.x[i][j] += (a.x[i][k] * b.x[k][j]) % MOD;
            }
            c.x[i][j] %= MOD;
        }
    }
    return c;
}

Matrix operator ^(const Matrix &mat, const long long k)
{
    Matrix tmp = mat;
    Matrix res;
    for (int i = 0; i < 5; ++i)
    {
        res.x[i][i] = 1;
    }
    for (int i = 0; (1LL << i) <= k; ++i)
    {
        if (k & (1LL << i))
        {
            res = res * tmp;
        }
        tmp = tmp * tmp;
    }
    return res;
}

int main()
{
    long long N;
    long long A0, AX, AY;
    long long B0, BX, BY;
    while (~scanf("%I64d", &N))
    {
        scanf("%I64d%I64d%I64d", &A0, &AX, &AY);
        scanf("%I64d%I64d%I64d", &B0, &BX, &BY);
        if (N == 0)
        {
            printf("0\n");
            continue;
        }
        Matrix mat;
        A0 %= MOD;
        AX %= MOD;
        AY %= MOD;
        B0 %= MOD;
        BX %= MOD;
        BY %= MOD;
        mat.x[0][0] = AX;
        mat.x[4][0] = AY;
        mat.x[1][1] = BX;
        mat.x[4][1] = BY;
        mat.x[0][2] = mat.x[0][3] = (AX * BY) % MOD;
        mat.x[1][2] = mat.x[1][3] = (AY * BX) % MOD;
        mat.x[2][2] = mat.x[2][3] = (AX * BX) % MOD;
        mat.x[3][3] = 1;
        mat.x[4][2] = mat.x[4][3] = (AY * BY) % MOD;
        mat.x[4][4] = 1;
        Matrix world = mat ^ (N - 1);
        long long ans = 0;
        ans += (A0 * world.x[0][3]) % MOD;
        ans += (B0 * world.x[1][3]) % MOD;
        ans += (((A0 * B0) % MOD) * world.x[2][3]) % MOD;
        ans += (((A0 * B0) % MOD) * world.x[3][3]) % MOD;
        ans += world.x[4][3];
        ans %= MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
