#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long a = 0, b = 0, c = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        a += m;
    }
    for (int i = 1; i < n; ++i) {
        cin >> m;
        b += m;
    }
    for (int i = 2; i < n; ++i) {
        cin >> m;
        c += m;
    }
    cout << a - b << endl;
    cout << b - c << endl;
    return 0;
}
