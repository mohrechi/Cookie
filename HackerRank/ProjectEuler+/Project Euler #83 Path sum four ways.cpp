#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int STEP_X[] = {0, 0, 1, -1};
const int STEP_Y[] = {1, -1, 0, 0};

int n;
long long a[MAXN][MAXN];
long long d[MAXN][MAXN];
bool visit[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push(pair<int, int>(1, 1));
    visit[1][1] = true;
    memset(d, 0x3f, sizeof(d));
    d[1][1] = a[1][1];
    while (not q.empty()) {
        auto u = q.front();
        q.pop();
        int x = u.first;
        int y = u.second;
        for (int k = 0; k < 4; ++k) {
            int tx = x + STEP_X[k];
            int ty = y + STEP_Y[k];
            if (1 <= tx and tx <= n) {
                if (1 <= ty and ty <= n) {
                    if (d[tx][ty] > d[x][y] + a[tx][ty]) {
                        d[tx][ty] = d[x][y] + a[tx][ty];
                        if (not visit[tx][ty]) {
                            visit[tx][ty] = true;
                            q.push(pair<int, int>(tx, ty));
                        }
                    }
                }
            }
        }
        visit[x][y] = false;
    }
    cout << d[n][n] << endl;
    return 0;
}
