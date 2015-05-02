#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string a, b;
    while (cin >> n >> a >> b) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += min((a[i] + 10 - b[i]) % 10, (b[i] + 10 - a[i]) % 10);
        }
        cout << sum << endl;
    }
    return 0;
}
