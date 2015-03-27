#include <bits/stdc++.h>
using namespace std;
const int DIR_X[] = {1, 0, -1, 0, -1, 1, -1, 1};
const int DIR_Y[] = {0, 1, 0, -1, -1, -1, 1, 1};

char field[105][105];
int dist[105][105];

int main() {
    int m, n, y, x;
    while (~scanf("%d%d%d%d", &m, &n, &y, &x)) {
        for (int i = n; i >= 1; --i) {
            scanf("%s", field[i] + 1);
        }
        queue<int> qx, qy;
        qx.push(x), qy.push(y);
        memset(dist, 0x3f, sizeof(dist));
        dist[x][y] = 0;
        int ans = 0;
        while (!qx.empty()) {
            x = qx.front();
            y = qy.front();
            qx.pop();
            qy.pop();
            for (int k = 0; k < 8; ++k) {
                int tx = x + DIR_X[k];
                int ty = y + DIR_Y[k];
                if (1 <= tx && tx <= n) {
                    if (1 <= ty && ty <= m) {
                        if (field[tx][ty] == '.') {
                            if (dist[tx][ty] > dist[x][y] + 1) {
                                dist[tx][ty] = dist[x][y] + 1;
                                qx.push(tx);
                                qy.push(ty);
                                ans = max(ans, dist[tx][ty]);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
