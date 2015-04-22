#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}

    Point(int _x, int _y) : x(_x), y(_y) {}

    inline friend istream& operator >>(istream& in, Point &p) {
        in >> p.x >> p.y;
        return in;
    }
} point[MAXN];

bool visit[MAXN];

inline Point operator -(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

inline int operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    int n;
    Point origin;
    while (cin >> n) {
        cin >> origin;
        for (int i = 0; i < n; ++i) {
            cin >> point[i];
            point[i] = point[i] - origin;
        }
        memset(visit, false, sizeof(visit));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visit[i]) {
                ++ans;
                for (int j = i + 1; j < n; ++j) {
                    if ((point[i] ^ point[j]) == 0) {
                        visit[j] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
