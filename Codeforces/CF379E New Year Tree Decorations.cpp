#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;
const double EPS = 1e-8;

int n, k;
int ys[MAXN][MAXN];
double area[MAXN];

inline double dblcmp(double x) {
    if (fabs(x) < EPS) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

struct Point {
    double x, y;
};

Point operator +(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator *(const Point &a, double b) {
    return {a.x * b, a.y * b};
}

double operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

double cross(const Point &a, const Point &b, const Point &o) {
    return (a - o) ^ (b - o);
}

bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    return max(a.x, b.x) >= min(c.x, d.x) &&
           max(c.x, d.x) >= min(a.x, b.x) &&
           max(a.y, b.y) >= min(c.y, d.y) &&
           max(c.y, d.y) >= min(a.y, b.y) &&
           dblcmp(cross(a, b, c)) * dblcmp(cross(a, b, d)) <= 0 &&
           dblcmp(cross(c, d, a)) * dblcmp(cross(c, d, b)) <= 0;
}

Point intersect(const Point &a, const Point &b, const Point &c, const Point &d) {
    double area1 = fabs(cross(a, c, d));
    double area2 = fabs(cross(b, c, d));
    double area = area1 + area2;
    double scale = area1 / area;
    return a + (b - a) * scale;
}


int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            scanf("%d", &ys[i][j]);
        }
    }
    for (int j = 0; j < k; ++j) {
        double lastArea = 0.0;
        vector<Point> ps;
        ps.push_back({0.0, 10000.0});
        ps.push_back({0.0, 0.0});
        ps.push_back({1.0, 0.0});
        ps.push_back({1.0, 10000.0});
        for (int i = 1; i <= n; ++i) {
            int interL = -1;
            int interR = -1;
            Point a = {0.0, (double)ys[i][j]};
            Point b = {1.0, (double)ys[i][j + 1]};
            Point iL, iR;
            for (int i = 1; i < (int)ps.size(); ++i) {
                Point& c = ps[i - 1];
                Point& d = ps[i];
                if (isIntersect(a, b, c, d)) {
                    iL = intersect(a, b, c, d);
                    interL = i;
                    break;
                }
            }
            for (int i = (int)ps.size() - 2; i >= 0; --i) {
                Point& c = ps[i];
                Point& d = ps[i + 1];
                if (isIntersect(a, b, c, d)) {
                    iR = intersect(a, b, c, d);
                    interR = i;
                    break;
                }
            }
            if (interL != -1 && interR != -1) {
                vector<Point> newPs;
                for (int i = 0; i < interL; ++i) {
                    newPs.push_back(ps[i]);
                }
                newPs.push_back(iL);
                newPs.push_back(iR);
                for (int i = interR + 1; i < (int)ps.size(); ++i) {
                    newPs.push_back(ps[i]);
                }
                ps.swap(newPs);
                double currentArea = 0.0;
                for (int i = 1; i < (int)ps.size(); ++i) {
                    currentArea += (ps[i].y + ps[i - 1].y) * (ps[i].x - ps[i - 1].x) * 0.5;
                }
                area[i] += currentArea - lastArea;
                lastArea = currentArea;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%.10f\n", area[i]);
    }
    return 0;
}
