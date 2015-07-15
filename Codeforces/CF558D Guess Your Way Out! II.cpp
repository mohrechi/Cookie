#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, q;
    map<long long, int> m;
    ios::sync_with_stdio(false);
    cin >> h >> q;
    long long ll = 1LL << (h - 1);
    long long rr = (1LL << h);
    m[ll] = 0; m[rr] = 0;
    for (int i = 0; i < q; ++i) {
        long long x, l, r, a;
        cin >> x >> l >> r >> a;
        for (int j = x + 1; j <= h; ++j) {
            l <<= 1;
            (r <<= 1) |= 1;
        }
        if (a == 1) {
            ++m[l], --m[r + 1];
        } else {
            ++m[ll], --m[l];
            ++m[r + 1], --m[rr];
        }
    }
    long long cnt = 0, pos = 0, last = -1, s = 0;
    for (auto p : m) {
        s += p.second;
        if (last != -1) {
            cnt += p.first - last;
            pos = last;
        }
        last = s == q ? p.first : -1;
    }
    if (cnt == 0) {
        cout << "Game cheated!" << endl;
    } else if (cnt == 1) {
        cout << pos << endl;
    } else {
        cout << "Data not sufficient!" << endl;
    }
    return 0;
}
