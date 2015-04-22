#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const double EPS = 1e-12;

int n;
struct Point {
    int index;
    double x, y;
    Point() : x(0.0), y(0.0) {
    }
    Point(double _x, double _y) : x(_x), y(_y) {
    }
} point[MAXN];

inline int compare(const double &x) {
    if (fabs(x) < EPS) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

inline int compare(const double &x, const double &y) {
    return compare(x - y);
}

inline Point operator +(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

inline Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

inline double operator *(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

inline double operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

inline double cross(const Point &a, const Point &b, const Point &o) {
    return (a - o) ^ (b - o);
}

inline bool operator <(const Point &a, const Point &b) {
    if (compare(a.y, b.y) == 0) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

inline bool operator ==(const Point &a, const Point &b) {
    return compare(a.x, b.x) == 0 && compare(a.y, b.y) == 0;
}

int stk[MAXN], top;

void graham() {
    if (n == 1) {
        top = 1;
        stk[0] = 0;
        return;
    }
    sort(point, point + n);
    top = 2;
    stk[0] = 0, stk[1] = 1;
    for (int i = 2; i < n; ++i) {
        while (top > 1 && compare(cross(point[i], point[stk[top - 1]], point[stk[top - 2]])) >= 0) {
            --top;
        }
        stk[top++] = i;
    }
    int halfTop = top;
    stk[top++] = n - 2;
    for (int i = n - 3; i >= 0; --i) {
        while (top > halfTop && compare(cross(point[i], point[stk[top - 1]], point[stk[top - 2]])) >= 0) {
            --top;
        }
        stk[top++] = i;
    }
}

bool win[MAXN];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            point[i].index = i + 1;
            scanf("%lf%lf", &point[i].x, &point[i].y);
            point[i].x = 1e6 / point[i].x;
            point[i].y = 1e6 / point[i].y;
        }
        graham();
        memset(win, false, sizeof(win));
        for (int i = top - 1; i >= 0; --i) {
            win[point[stk[i]].index] = true;
            if (compare(point[stk[i - 1]].x, point[stk[i]].x) >= 0) {
                break;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (win[point[i - 1].index] && point[i] == point[i - 1]) {
                win[point[i].index] = true;
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (win[point[i + 1].index] && point[i] == point[i + 1]) {
                win[point[i].index] = true;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (win[i]) {
                printf("%d ", i);
            }
        }
        putchar('\n');
    }
    return 0;
}
