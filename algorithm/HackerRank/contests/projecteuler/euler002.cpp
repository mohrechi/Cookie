#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Matrix
{
    long long data[3][3];
};

Matrix operator +(const Matrix &a, const Matrix &b)
{
    Matrix c;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

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
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

Matrix operator ^(const Matrix &a, const int b)
{
    Matrix c = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix tmp = a;
    for (int i = 0; (1LL << i) <= b; ++i)
    {
        if (b & (1LL << i))
        {
            c = c * tmp;
        }
        tmp = tmp * tmp;
    }
    return c;
}

Matrix getMatrix(int n)
{
    Matrix fib = {1, 1, 1, 0, 1, 1, 0, 1, 0};
    return fib ^ (n - 2);
}

long long getSum(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 3;
    Matrix fib = getMatrix(n);
    return fib.data[0][0] * 3 + fib.data[0][1] * 2 + fib.data[0][2];
}

long long getFib(int n)
{
    if (n <= 1) return 1;
    if (n == 2) return 2;
    Matrix fib = getMatrix(n);
    return fib.data[1][1] * 2 + fib.data[1][2];
}

int main()
{
    int T;
    long long N;
    long long fibs[100];
    for (int i = 0; i < 100; ++i)
    {
        fibs[i] = getFib(i);
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &N);
        for (int i = 1; i < 100; ++i)
        {
            if (fibs[i] > N)
            {
                long long ans = getSum((i - 3) / 3 * 3 + 2);
                ans = (ans + 1) / 2;
                printf("%lld\n", ans);
                break;
            }
        }
    }
    return 0;
}
