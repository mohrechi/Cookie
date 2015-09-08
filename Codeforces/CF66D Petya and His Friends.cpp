#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
    } else {
        cout << 6 << endl << 10 << endl << 15 << endl;
        for (int i = 4; i <= n; ++i) {
            cout << 30 * i << endl;
        }
    }
    return 0;
}
