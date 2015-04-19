#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

int n, m, cost;
char board[MAXN];

bool visit[MAXN];
int dist[MAXN];
int q[MAXN], p[MAXN], pNum;

inline int getIndex(const int &x, const int &y) {
    return x * m + y;
}

inline int getX(const int &index) {
    return index / m;
}

inline int getY(const int &index) {
    return index % m;
}

void spfa(int index) {
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    visit[index] = true;
    dist[index] = 0;
    q[0] = index;
    while (front != rear) {
        index = q[front];
        int x = getX(index);
        int y = getY(index);
        for (int k = 0; k < 4; ++k) {
            int tx = x + DIR_X[k];
            int ty = y + DIR_Y[k];
            if (0 <= tx && tx < n) {
                if (0 <= ty && ty < m) {
                    int tIndex = getIndex(tx, ty);
                    if (board[tIndex] != '#') {
                        if (board[tIndex] == 'P') {
                            for (int i = 0; i < pNum; ++i) {
                                tIndex = p[i];
                                if (dist[tIndex] > dist[index]) {
                                    dist[tIndex] = dist[index];
                                    if (!visit[tIndex]) {
                                        visit[tIndex] = true;
                                        q[rear] = tIndex;
                                        if (++rear >= MAXN) {
                                            rear = 0;
                                        }
                                    }
                                }
                            }
                        } else {
                            if (dist[tIndex] > dist[index] + (board[tIndex] == '*')) {
                                dist[tIndex] = dist[index] + (board[tIndex] == '*');
                                if (!visit[tIndex]) {
                                    visit[tIndex] = true;
                                    q[rear] = tIndex;
                                    if (++rear >= MAXN) {
                                        rear = 0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        visit[index] = false;
        if (++front >= MAXN) {
            front = 0;
        }
    }
}

int main() {
    int sx, sy, ex, ey;
    while (~scanf("%d%d%d", &n, &m, &cost)) {
        pNum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", board + m * i);
            for (int j = 0; j < m; ++j) {
                int index = getIndex(i, j);
                if (board[index] == 'Y') {
                    sx = i;
                    sy = j;
                } else if (board[index] == 'C') {
                    ex = i;
                    ey = j;
                } else if (board[index] == 'P') {
                    p[pNum] = index;
                    ++pNum;
                }
            }
        }
        spfa(getIndex(sx, sy));
        if (dist[getIndex(ex, ey)] == 0x3f3f3f3f) {
            cout << "hentai!" << endl;
        } else {
            cout << 1LL * dist[getIndex(ex, ey)] * cost << endl;;
        }
    }
    return 0;
}
