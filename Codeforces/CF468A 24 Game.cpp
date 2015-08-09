#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    ios::sync_with_stdio(false);
    while (cin >> n) {
        if (n <= 3) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            if (n & 1) {
                cout << "1 * 2 = 2" << endl;
                cout << "3 + 4 = 7" << endl;
                cout << "7 + 5 = 12" << endl;
                cout << "2 * 12 = 24" << endl;
            } else {
                cout << "1 * 2 = 2" << endl;
                cout << "2 * 3 = 6" << endl;
                cout << "6 * 4 = 24" << endl;
            }
            for (int i = 5 + (n & 1); i < n; i += 2) {
                cout << i + 1 << " - " << i << " = 1" << endl;
                cout << "1 * 24 = 24" << endl;
            }
        }
    }
    return 0;
}
