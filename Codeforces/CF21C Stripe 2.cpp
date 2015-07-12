#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, sum;
int a[MAXN];
vector<int> v1, v2;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3) {
        cout << 0 << endl;
    } else {
        int m = sum / 3;
        for (int i = 0, j = 0; i < n - 1; ++i) {
            j += a[i];
            if (j == m) {
                v1.push_back(i);
            }
            if (j == m * 2) {
                v2.push_back(i);
            }
        }
        long long ans = 0;
        for (int i = 0, j = 0; i < (int)v1.size(); ++i) {
            while (j < (int)v2.size() and v2[j] <= v1[i]) {
                ++j;
            }
            ans += v2.size() - j;
        }
        cout << ans << endl;
    }
}
