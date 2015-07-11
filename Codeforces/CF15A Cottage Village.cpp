#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

struct House {
    int x, a;
    inline void input() {
        cin >> x >> a;
        x *= 2;
    }
    inline int left() {
        return x - a;
    }
    inline int right() {
        return x + a;
    }
    bool operator <(const House &house) const {
        return x < house.x;
    }
} house[MAXN];

int main() {
    int n, t;
    ios::sync_with_stdio(false);
    cin >> n >> t;
    t <<= 1;
    for (int i = 0; i < n; ++i) {
        house[i].input();
    }
    sort(house, house + n);
    int ans = 2;
    for (int i = 1; i < n; ++i) {
        int d = house[i].left() - house[i - 1].right();
        if (d == t) {
            ++ans;
        } else if (d > t) {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
