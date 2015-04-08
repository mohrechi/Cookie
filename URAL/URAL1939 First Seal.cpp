#include <bits/stdc++.h>
using namespace std;

int main() {
    double l, h, H;
    double v, x, a;
    cin >> l >> h >> H;
    cin >> v >> x >> a;
    double t = (H - h) / x;
    double s1 = v * t - l;
    double s2 = v * v / a * 0.5;
    if (s1 < s2 + 1e-8) {
        cout << "Crash" << endl;
    } else {
        cout << "Safe" << endl;
    }
    return 0;
}
