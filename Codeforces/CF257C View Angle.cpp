#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const double PI = acos(-1.0);

struct Point {
    int x, y;
    double ang;
    bool operator <(const Point &point) const {
        return ang < point.ang;
    }
} points[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i].x, &points[i].y);
        points[i].ang = atan2(points[i].y, points[i].x);
    }
    bool line = true;
    for (int i = 1; i < n; ++i) {
        if (points[i].x * points[i - 1].y != points[i].y * points[i - 1].x) {
            line = false;
            break;
        }
    }
    double ans = 10;
    if (line) {
        ans = 0;
    } else {
        sort(points, points + n);
        points[n] = points[0];
        for (int i = 0; i < n; ++i) {
            double tmp = points[i + 1].ang - points[i].ang;
            while (tmp < 0.0) {
                tmp += PI * 2;
            }
            ans = min(ans, PI * 2 - tmp);
        }
        ans = ans / PI * 180;
    }
    printf("%.10f\n", ans);
    return 0;
}
