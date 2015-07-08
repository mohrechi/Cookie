#include <bits/stdc++.h>
using namespace std;

int main() {
    long long r, g, b;
    cin >> r >> g >> b;
    if (g < b) {
        swap(g, b);
    }
    if (r < g) {
        swap(r, g);
    }
    if (r / 2 > g + b) {
        cout << g + b << endl;
    } else {
        cout << (r + g + b) / 3 << endl;
    }
    return 0;
}
