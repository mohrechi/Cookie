#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

struct Matrix {
    long long data[3][3];
    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0;
            }
        }
    }
    long long sum() {
        long long ret = 0;
        for (int i = 0; i < 3; ++i) {
            ret += data[i][0];
        }
        return ret % MOD;
    }
};

Matrix operator*(const Matrix& a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c.data[i][j] = 0;
            for (int k = 0; k < 3; ++k) {
                c.data[i][j] += a.data[i][k] * b.data[k][j] % MOD;
            }
            c.data[i][j] %= MOD;
        }
    }
    return c;
}

int main() {
    long long n;
    while (~scanf("%lld", &n)) {
        if (n == 1) {
            puts("2");
            continue;
        } else if (n == 2) {
            puts("3");
            continue;
        }
        n -= 2;
        Matrix m, v;
        m.data[0][2] = 1;
        m.data[1][0] = 1;
        m.data[1][2] = 1;
        m.data[2][1] = 1;
        v.data[0][0] = 1;
        v.data[1][0] = 1;
        v.data[2][0] = 1;
        Matrix acc;
        acc.data[0][0] = 1;
        acc.data[1][1] = 1;
        acc.data[2][2] = 1;
        for (int i = 0; (1LL << i) <= n; ++i) {
            if ((1LL << i) & n) {
                acc = acc * m;
            }
            m = m * m;
        }
        acc = acc * v;
        printf("%lld\n", acc.sum());
    }
    return 0;
}
