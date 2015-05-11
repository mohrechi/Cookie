#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e6 + 10;

int steps[MAXN * 10];
int ans[MAXN], num[MAXN];

int find(long long x) {
    if (x == 1) {
        return 0;
    }
    if (x >= MAXN * 10) {
        if (x & 1) {
            return find(x * 3 + 1) + 1;
        }
        return find(x >> 1) + 1;
    }
    if (steps[x]) {
        return steps[x];
    }
    if (x & 1) {
        steps[x] = find(x * 3 + 1) + 1;
    } else {
        steps[x] = find(x >> 1) + 1;
    }
    return steps[x];
}

int main() {
    int T, N;
    steps[1] = 0;
    ans[1] = 0;
    num[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (find(i) >= ans[i - 1]) {
            ans[i] = find(i);
            num[i] = i;
        } else {
            ans[i] = ans[i - 1];
            num[i] = num[i - 1];
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << num[N] << endl;
    }
    return 0;
}
