#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    if (n == 1 && t == 10) {
        cout << -1 << endl;
    } else {
        if (t == 10) {
            t = 1;
        }
        cout << t;
        while (--n) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
