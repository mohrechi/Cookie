#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const double EPS = 1e-9;

int n;
struct Point {
    long long x, y;
} poly[MAXN * 2];
long double pow2[MAXN];

inline Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

inline long long operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long gcd(const Point &p) {
    return __gcd(abs(p.x), abs(p.y));
}

int main() {
    scanf("%d", &n);
    pow2[0] = 1.0;
    for (int i = 0; i < n; ++i) {
        scanf("%I64d%I64d", &poly[i].x, &poly[i].y);
        poly[i + n] = poly[i];
    }
    for (int i = 1; i <= n; ++i) {
        pow2[i] = pow2[i - 1] * 2.0;
    }
    long double A = 0.0;
    long double b = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= min(60, n - 2); ++j) {
            long double prob = (1.0 - 1.0 / pow2[n - (j + 1)]) / (pow2[j + 1] - (1.0 + n + (double)n * (n - 1) / 2) / pow2[n - (j + 1)]);
            A += prob * (poly[i] ^ poly[i + j]) / 2;
            b += prob * gcd(poly[i] - poly[i + j]);
        }
    }
    cout << fixed << setprecision(10) << A + 1 - b / 2 << endl;
    return 0;
}
