#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const double PI = acos(-1.0);
const double EPS = 1e-8;

int n;
struct Point {
    double x, y;
    friend istream& operator >>(istream& in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
    friend Point operator +(const Point &a, const Point &b) {
        return {a.x + b.x, a.y + b.y};
    }
    friend Point operator -(const Point &a, const Point &b) {
        return {a.x - b.x, a.y - b.y};
    }
    friend Point operator *(const Point &a, double b) {
        return {a.x * b, a.y * b};
    }
    friend bool operator !=(const Point &a, const Point &b) {
        return fabs(a.x - b.x) > EPS || fabs(a.y - b.y) > EPS;
    }
} center, points[MAXN];

inline double square(double x) {
    return x * x;
}

inline double dist(const Point &a, const Point &b) {
    return sqrt(square(a.x - b.x) + square(a.y - b.y));
}

int main() {
    double maxR = 0.0, minR = 1e100;
    ios::sync_with_stdio(false);
    cin >> n >> center;
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
        maxR = max(maxR, dist(center, points[i]));
    }
    points[n] = points[0];
    for (int i = 0; i < n; ++i) {
        Point l = points[i], r = points[i + 1];
        while (l != r) {
            auto ll = l + (r - l) * (1.0 / 3.0);
            auto rr = l + (r - l) * (2.0 / 3.0);
            auto dl = dist(center, ll);
            auto dr = dist(center, rr);
            if (dl > dr) {
                l = ll;
            } else {
                r = rr;
            }
        }
        minR = min(minR, dist(center, l));
    }
    cout << setprecision(10) << (maxR * maxR - minR * minR) * PI << endl;
    return 0;
}
