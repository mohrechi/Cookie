#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n;
    ios::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        cout << ((n & 1) ^ 1) << endl;
    }
    return 0;
}
