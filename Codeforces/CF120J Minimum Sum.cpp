#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXL = log2(MAXN) + 1;

int n;
struct Point {
    int x, y, k, idx;
    void input() {
        scanf("%d%d", &x, &y);
        if (y >= 0) {
            if (x >= 0) {
                k = 1;
            } else {
                k = 2;
            }
        } else {
            if (x >= 0) {
                k = 3;
            } else {
                k = 4;
            }
        }
        x = abs(x);
        y = abs(y);
    }
    inline double len() const {
        return sqrt(x * x + y * y);
    }
} pt[MAXL][MAXN];

bool compareX(const Point &a, const Point &b) {
    return a.x < b.x;
}

bool compareY(const Point &a, const Point &b) {
    return a.y < b.y;
}

inline Point operator -(const Point &a, const Point &b) {
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

inline double dist(const Point &a, const Point &b) {
    return (b - a).len();
}

double ans;
int p1, p2;

double dfs(int layer, int l, int r) {
    double minDist = 1e100;
    if (r - l <= 5) {
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                double d = dist(pt[layer][i], pt[layer][j]);
                minDist = min(minDist, d);
                if (d < ans) {
                    ans = d;
                    p1 = pt[layer][i].idx;
                    p2 = pt[layer][j].idx;
                }
            }
        }
    } else {
        for (int i = l; i < r; ++i) {
            pt[layer + 1][i] = pt[layer][i];
        }
        sort(pt[layer + 1] + l, pt[layer + 1] + r, compareX);
        int mid = (l + r) / 2;
        double div = (pt[layer + 1][mid - 1].x + pt[layer + 1][mid].x) * 0.5;
        minDist = min(minDist, dfs(layer + 1, l, mid));
        minDist = min(minDist, dfs(layer + 1, mid, r));
        int m = l;
        for (int i = l; i < r; ++i) {
            if (div - minDist <= pt[layer][i].x && pt[layer][i].x <= div + minDist) {
                pt[layer + 1][m++] = pt[layer][i];
            }
        }
        sort(pt[layer + 1] + l, pt[layer + 1] + m, compareY);
        for (int i = l; i < m; ++i) {
            for (int j = i + 1; j < i + 8 && j < m; ++j) {
                double d = dist(pt[layer + 1][i], pt[layer + 1][j]);
                minDist = min(minDist, d);
                if (d < ans) {
                    ans = d;
                    p1 = pt[layer + 1][i].idx;
                    p2 = pt[layer + 1][j].idx;
                }
            }
        }
    }
    return minDist;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        pt[0][i].input();
        pt[0][i].idx = i;
    }
    ans = 1e100;
    dfs(0, 0, n);
    printf("%d %d %d %d\n", p1 + 1, pt[0][p1].k, p2 + 1, 5 - pt[0][p2].k);
    return 0;
}
