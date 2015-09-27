#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i < n - k; ++i) {
            cout << i << " ";
        }
        int l = n - k, r = n;
        while (l < r) {
            cout << l++ << " ";
            cout << r-- << " ";
        }
        if (l == r) {
            cout << l;
        }
        cout << endl;
    }
    return 0;
}
