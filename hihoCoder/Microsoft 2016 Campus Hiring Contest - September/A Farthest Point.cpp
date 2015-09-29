#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double dblcmp(double x) {
    if (fabs(x) < 1e-8) {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

struct Ans {
    int x, y;
    double dist;
    bool operator >(const Ans &a) const {
        if (dblcmp(dist - a.dist) == 0) {
            if (x == a.x) {
                return y > a.y;
            }
            return x > a.x;
        }
        return dist > a.dist;
    }
} ans;

double x, y, r;

void tryPos(int i, int j) {
    double di = i - x;
    double dj = j - y;
    double dist = di * di + dj * dj;
    Ans temp;
    temp.x = i;
    temp.y = j;
    temp.dist = sqrt(dist);
    if (temp > ans) {
        ans = temp;
    }
}

int main() {
    cin >> x >> y >> r;
    int lx = floor(x - r);
    int rx = ceil(x + r);
    ans.dist = -1.0;
    for (int i = lx; i <= rx; ++i) {
        double dy = r * r - (i - x) * (i - x);
        if (dy >= 0.0) {
            dy = sqrt(dy);
            tryPos(i, floor(y + dy));
            tryPos(i, ceil(y - dy));
        }
    }
    printf("%d %d\n", ans.x, ans.y);
    return 0;
}
