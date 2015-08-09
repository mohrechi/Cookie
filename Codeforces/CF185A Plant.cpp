#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

struct Matrix {
    long long data[2][2];
    Matrix() {
        memset(data, 0, sizeof(data));
    }
};

Matrix operator +(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            c.data[i][j] = (a.data[i][j] + b.data[i][j]) % MOD;
    return c;
}

Matrix operator *(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int k = 0; k < 2; ++k)
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                (c.data[i][j] += (a.data[i][k] * b.data[k][j]) % MOD) %= MOD;
    return c;
}

Matrix fastPow(Matrix x, long long y) {
    Matrix ret;
    ret.data[0][0] = ret.data[1][1] = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = ret * x;
        }
        x = x * x;
    }
    return ret;
}

int main() {
    long long n;
    while (cin >> n) {
        Matrix trans;
        trans.data[0][0] = 3, trans.data[0][1] = 1;
        trans.data[1][0] = 1, trans.data[1][1] = 3;
        trans = fastPow(trans, n);
        cout << trans.data[0][0] << endl;
    }
    return 0;
}
