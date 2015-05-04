#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

struct Probability {
    double r, s, p;

    Probability() :
        r(-1.0), s(0.0), p(0.0) {
    }

    Probability(double _r, double _s, double _p) :
        r(_r), s(_s), p(_p) {
    }

    inline bool initialized() const {
        return r > -0.5;
    }

    friend Probability operator +(const Probability &a, const Probability &b) {
        return {a.r + b.r, a.s + b.s, a.p + b.p};
    }

    friend Probability operator *(const Probability &a, const double &b) {
        return {a.r * b, a.s * b, a.p * b};
    }

    friend ostream& operator <<(ostream &out, const Probability &p) {
        out.precision(10);
        out.setf(ios::fixed);
        out << p.r << ' ' << p.s << ' ' << p.p;
        return out;
    }
};

Probability dp[MAXN][MAXN][MAXN];

const Probability& get(int r, int s, int p) {
    if (dp[r][s][p].initialized()) {
        return dp[r][s][p];
    }
    if (r and s == 0 and p == 0) {
        return dp[1][0][0] = {1.0, 0.0, 0.0};
    }
    if (r == 0 and s and p == 0) {
        return dp[0][1][0] = {0.0, 1.0, 0.0};
    }
    if (r == 0 and s == 0 and p) {
        return dp[0][0][1] = {0.0, 0.0, 1.0};
    }
    double total = r * s + s * p + p * r;
    dp[r][s][p] = {0.0, 0.0, 0.0};
    if (r and s) {
        dp[r][s][p] = dp[r][s][p] + get(r, s - 1, p) * (r * s / total);
    }
    if (s and p) {
        dp[r][s][p] = dp[r][s][p] + get(r, s, p - 1) * (s * p / total);
    }
    if (p and r) {
        dp[r][s][p] = dp[r][s][p] + get(r - 1, s, p) * (p * r / total);
    }
    return dp[r][s][p];
}

int main() {
    ios::sync_with_stdio(false);
    int r, s, p;
    while (cin >> r >> s >> p) {
        cout << get(r, s, p) << endl;
    }
    return 0;
}
