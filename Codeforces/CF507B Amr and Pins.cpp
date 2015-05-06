#include <bits/stdc++.h>
using namespace std;

int main() {
    double r, x1, y1, x2, y2;
    ios::sync_with_stdio(false);
    while (cin >> r >> x1 >> y1 >> x2 >> y2) {
        double d = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0));
        cout << ceil(d / r * 0.5) << endl;
    }
    return 0;
}
