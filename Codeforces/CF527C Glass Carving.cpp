#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, n;
    while (cin >> w >> h >> n) {
        string op;
        int pos;
        set<int> x;
        set<int, greater<int>> rx;
        x.insert(0), rx.insert(0);
        x.insert(w), rx.insert(w);
        set<int> y;
        set<int, greater<int>> ry;
        y.insert(0), ry.insert(0);
        y.insert(h), ry.insert(h);
        multiset<int, greater<int>> horizon;
        horizon.insert(w);
        multiset<int, greater<int>> vertical;
        vertical.insert(h);
        while (n--) {
            cin >> op >> pos;
            if (op[0] == 'V') {
                int x1 = *x.upper_bound(pos);
                int x2 = *rx.upper_bound(pos);
                x.insert(pos);
                rx.insert(pos);
                horizon.erase(horizon.find(abs(x1 - x2)));
                horizon.insert(abs(pos - x1));
                horizon.insert(abs(pos - x2));
            } else {
                int y1 = *y.upper_bound(pos);
                int y2 = *ry.upper_bound(pos);
                y.insert(pos);
                ry.insert(pos);
                vertical.erase(vertical.find(abs(y1 - y2)));
                vertical.insert(abs(pos - y1));
                vertical.insert(abs(pos - y2));
            }
            cout << 1LL * *horizon.begin() * *vertical.begin() << endl;
        }
    }
    return 0;
}
