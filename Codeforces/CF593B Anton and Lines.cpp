#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x1, x2;
    long long k, b;
    ios::sync_with_stdio(false);
    cin >> n >> x1 >> x2;
    vector<pair<long long, long long>> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> k >> b;
        vals[i] = {k * x1 + b, k * x2 + b};
    }
    sort(vals.begin(), vals.end());
    for (int i = 1; i < n; ++i) {
        if (vals[i].second < vals[i - 1].second) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
