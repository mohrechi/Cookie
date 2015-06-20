#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;

int n;
struct Point {
    int x, y;
} points[MAXN], sorted[MAXN], center;

inline Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

inline int operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

inline int cross(const Point &a, const Point &b) {
    return (a - center) ^ (b - center);
}

bool operator <(const Point &a, const Point &b) {
    return cross(a, b) < 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    long long ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n - 1; ++i) {
        center = points[i];
        for (int j = i + 1; j < n; ++j) {
            if (points[j].y < center.y) {
                sorted[j] = {center.x * 2 - points[j].x, center.y * 2 - points[j].y};
            } else {
                sorted[j] = points[j];
            }
        }
        sort(sorted + i + 1, sorted + n);
        int start = i + 1;
        for (int j = i + 1; j < n - 1; ++j) {
            if (cross(sorted[j], sorted[j + 1])) {
                start = j + 1;
                break;
            }
        }
        for (int j = start; ;) {
            int k = j + 1;
            if (k == n) {
                k = i + 1;
            }
            int len = 1;
            while (k != start) {
                if (cross(sorted[j], sorted[k])) {
                    break;
                }
                ++len;
                if (++k == n) {
                    k = i + 1;
                }
            }
            if (len >= 2) {
                ans -= len * (len - 1) / 2;
            }
            if (k == start) {
                break;
            }
            j = k;
        }
    }
    cout << ans << endl;
    return 0;
}
