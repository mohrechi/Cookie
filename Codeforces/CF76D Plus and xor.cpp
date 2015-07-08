#include <bits/stdc++.h>
using namespace std;

int main() {
    typedef unsigned long long uint64;
    uint64 a, b, x, y;
    cin >> a >> b;
    x = (a - b) / 2;
    y = x + b;
    if (x + y == a and (x ^ y) == b) {
        cout << x << " " << y << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
