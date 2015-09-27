#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, q;
set<int> ys;
struct Point {
    int x, y;
    bool operator <(const Point &point) const {
        if (y == point.y) {
            return x < point.x;
        }
        return y < point.y;
    }
} leftPoly[MAXN], rightPoly[MAXN], camera[MAXN];

inline int readInt() {
    char ch;
    bool neg = false;
    for (ch = getchar(); !('0' <= ch && ch <= '9'); ch = getchar()) {
        if (ch == '-') {
            neg = true;
        }
    }
    int num = ch - '0';
    for (ch = getchar(); '0' <= ch && ch <= '9'; ch = getchar()) {
        num = num * 10 + ch - '0';
    }
    return neg ? -num : num;
}

inline void readPoly(int &n, Point poly[]) {
    n = readInt();
    for (int i = 0; i < n; ++i) {
        poly[i].x = readInt();
        poly[i].y = readInt();
        ys.insert(poly[i].y);
    }
}

inline double getX(const Point &p1, const Point &p2, double y) {
    return p1.x + 1.0 * (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
}

int main() {
    double ans = 1e100;
    readPoly(n, leftPoly);
    readPoly(m, rightPoly);
    readPoly(q, camera);
    sort(camera, camera + q);
    int i = 1, j = 1, k = 0;
    for (auto y : ys) {
        if (y < leftPoly[0].y) {
            continue;
        }
        if (y > leftPoly[n - 1].y) {
            break;
        }
        while (i < n - 1 && leftPoly[i].y < y) {
            ++i;
        }
        while (j < m - 1 && rightPoly[j].y < y) {
            ++j;
        }
        double leftX = getX(leftPoly[i - 1], leftPoly[i], y);
        double rightX = getX(rightPoly[j - 1], rightPoly[j], y);
        while (k < q && (camera[k].y < y || (camera[k].y == y && camera[k].x <= leftX))) {
            ++k;
        }
        double subMax = 0.0;
        while (true) {
            if (k < q && camera[k].y == y && camera[k].x < rightX) {
                subMax = max(subMax, camera[k].x - leftX);
                leftX = camera[k].x;
                ++k;
            } else {
                subMax = max(subMax, rightX - leftX);
                break;
            }
        }
        ans = min(ans, subMax);
    }
    printf("%.8f\n", ans);
    return 0;
}
