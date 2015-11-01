#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int t, n, k;
int sx, sy;
char m[3][MAXN];
bool v[3][MAXN];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        memset(m, '.', sizeof(m));
        memset(v, false, sizeof(v));
        for (int i = 0; i < 3; ++i) {
            scanf("%s", m[i]);
            m[i][n] = '.';
            for (int j = 0; j < n; ++j) {
                if (m[i][j] == 's') {
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        queue<pair<int, int>> q;
        q.push({sx, sy});
        bool possible = false;
        while (!q.empty() && !possible) {
            auto u = q.front();
            q.pop();
            int x = u.first;
            int y = u.second;
            if (m[x][y + 1] == '.') {
                for (int k = -1; k <= 1; ++k) {
                    int tx = x + k;
                    if (0 <= tx && tx < 3) {
                        if (m[tx][y + 1] == '.' && m[tx][y + 2] == '.' && m[tx][y + 3] == '.') {
                            if (y + 3 >= n) {
                                possible = true;
                                break;
                            }
                            if (!v[tx][y + 3]) {
                                v[tx][y + 3] = true;
                                q.push({tx, y + 3});
                            }
                        }
                    }
                }
            }
        }
        puts(possible ? "YES" : "NO");
    }
    return 0;
}
