#include <bits/stdc++.h>
using namespace std;
const int MAXM = 101;
const int MOD = 1e9 + 7;

int cnt[MAXM], dp[MAXM];

struct Matrix {
    int data[MAXM][MAXM];
    Matrix() {
        for (int i = 0; i < MAXM; ++i) {
            for (int j = 0; j < MAXM; ++j) {
                data[i][j] = 0;
            }
        }
    }
};

Matrix operator +(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            c.data[i][j] = (a.data[i][j] + b.data[i][j]) % MOD;
        }
    }
    return c;
}

Matrix operator *(const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < MAXM; ++i) {
        for (int j = 0; j < MAXM; ++j) {
            for (int k = 0; k < MAXM; ++k) {
                c.data[i][j] += 1LL * a.data[i][k] * b.data[k][j] % MOD;
                c.data[i][j] %= MOD;
            }
        }
    }
    return c;
}

Matrix fastPow(Matrix x, int y) {
    Matrix ret;
    for (int i = 0; i < MAXM; ++i) {
        ret.data[i][i] = 1;
    }
    for (int i = 0; (1 << i) <= y; ++i) {
        if (y & (1 << i)) {
            ret = ret * x;
        }
        x = x * x;
    }
    return ret;
}

int main() {
    int n, x, d;
    while (cin >> n >> x) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cin >> d;
            ++cnt[d];
        }
        int sum = 1;
        dp[0] = 1;
        for (int i = 1; i < min(MAXM, x + 1); ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += 1LL * cnt[j] * dp[i - j] % MOD;
                dp[i] %= MOD;
            }
            sum = (sum + dp[i]) % MOD;
        }
        if (x < MAXM) {
            cout << sum << endl;
        } else {
            Matrix v;
            for (int i = 0; i < 100; ++i) {
                v.data[i][0] = dp[i + 1];
            }
            v.data[100][0] = sum;
            Matrix m;
            for (int i = 0; i < 99; ++i) {
                m.data[i][i + 1] = 1;
            }
            for (int j = 0; j < 100; ++j) {
                m.data[99][j] = m.data[100][j] = cnt[100 - j];
            }
            m.data[100][100] = 1;
            v = fastPow(m, x - 100) * v;
            cout << v.data[100][0] << endl;
        }
    }
    return 0;
}
