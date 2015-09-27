#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
    inline void input() {
        cin >> x >> y;
    }
} a, b, c;

Point operator -(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

long long operator ^(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

long long cross(const Point &a, const Point &b, const Point &o) {
    return (a - o) ^ (b - o);
}

int main() {
    a.input();
    b.input();
    c.input();
    double val = cross(b, c, a);
    if (val == 0) {
        cout << "TOWARDS" << endl;
    } else if (val < 0) {
        cout << "RIGHT" << endl;
    } else {
        cout << "LEFT" << endl;
    }
    return 0;
}
