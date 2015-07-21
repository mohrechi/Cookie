#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int STEP_X[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int STEP_Y[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    int x0, y0, x1, y1;
    int q, r, x, y;
    ios::sync_with_stdio(false);
    cin >> x0 >> y0 >> x1 >> y1;
    cin >> q;
    map<pair<int, int>, int> dists;
    while (q--) {
        cin >> r >> x >> y;
        for (int i = x; i <= y; ++i) {
            dists[{r, i}] = INF;
        }
    }
    if (dists.find({x0, y0}) == dists.end() or dists.find({x1, y1}) == dists.end()) {
        cout << -1 << endl;
    } else {
        dists[{x0, y0}] = 0;
        queue<pair<int, int>> q;
        q.push({x0, y0});
        while (not q.empty()) {
            auto u = q.front();
            int dist = dists[u];
            q.pop();
            for (int k = 0; k < 8; ++k) {
                int tx = u.first + STEP_X[k];
                int ty = u.second + STEP_Y[k];
                auto it = dists.find({tx, ty});
                if (it != dists.end() and it->second == INF) {
                    it->second = dist + 1;
                    if (tx == x1 and ty == y1) {
                        break;
                    }
                    q.push({tx, ty});
                }
            }
        }
        auto it = dists.find({x1, y1});
        if (it == dists.end() or it->second == INF) {
            cout << -1 << endl;
        } else {
            cout << it->second << endl;
        }
    }
    return 0;
}
