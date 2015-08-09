#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int main() {
    char a[MAXN], b[MAXN];
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int cntA = 0, cntB = 0;
    for (int i = 0; a[i]; ++i) {
        cntA += a[i] == '1';
    }
    if (cntA & 1) {
        ++cntA;
    }
    for (int i = 0; b[i]; ++i) {
        cntB += b[i] == '1';
    }
    cout << (cntA >= cntB ? "YES" : "NO") << endl;
    return 0;
}
