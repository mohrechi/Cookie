#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-18;

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
} b0, b1;

int dblcmp(double val) {
    if (fabs(val) < EPS) {
        return 0;
    }
    return val > 0 ? 1 : -1;
}

Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

double operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

struct Segment {
    Point u, v;
};

bool isIntersect(const Point &p, const Segment& seg) {
    return dblcmp(p ^ seg.u) * dblcmp(p ^ seg.v) <= 0;
}

struct Rect {
    Point p[4];
    Rect(const Point &a, const Point &b, const Point &c, const Point &d) {
        p[0] = a;
        p[1] = b;
        p[2] = c;
        p[3] = d;
    }
};

bool existsSub(const Rect &r1, const Rect &r2) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Segment seg = {r2.p[j], r2.p[(j + 1) % 4]};
            if (isIntersect(r1.p[i], seg)) {
                return true;
            }
        }
    }
    return false;
}

bool exists(const Rect &r1, const Rect &r2) {
    return existsSub(r1, r2) || existsSub(r2, r1);
}

int main() {
    int n = 1000000;
    cin >> b0.x >> b0.y >> b1.x >> b1.y;
    double l = 0.0, r = max(max(abs(b0.x), abs(b0.y)), max(abs(b1.x), abs(b1.y)));
    while (n--) {
        double mid = (l + r) * 0.5;
        Rect r1 = {Point(b0.x - mid, b0.y - mid),
                   Point(b0.x - mid, b0.y + mid),
                   Point(b0.x + mid, b0.y + mid),
                   Point(b0.x + mid, b0.y - mid)};
        Rect r2 = {Point(b1.x - mid, b1.y - mid),
                   Point(b1.x - mid, b1.y + mid),
                   Point(b1.x + mid, b1.y + mid),
                   Point(b1.x + mid, b1.y - mid)};
        if (exists(r1, r2)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", (l + r) * 0.5);
    return 0;
}
