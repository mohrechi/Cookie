#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        cout << (n * 6 - 1) * k << endl;
        for (int i = 0; i < n; ++i) {
            cout << (i * 6 + 1) * k << " ";
            cout << (i * 6 + 2) * k << " ";
            cout << (i * 6 + 3) * k << " ";
            cout << (i * 6 + 5) * k << endl;
        }
    }
    return 0;
}
