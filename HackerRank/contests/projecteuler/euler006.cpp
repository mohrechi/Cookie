#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;

long long a[MAXN], b[MAXN];

int main() {
    int T, N;
    for (long long i = 1; i < MAXN; ++i) {
        long long sum = (1 + i) * i / 2;
        a[i] = a[i - 1] + i * i;
        b[i] = sum * sum;
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << abs(a[N] - b[N]) << endl;
    }
    return 0;
}
