#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 155;
const int DIRX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int DIRY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m;
int board[MAXN][MAXN];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        int x, y;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &board[i][j]);
                if (board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        bool flag = true;
        if (n > 1 || m > 1) {
            int index = 1;
            while (index < n * m) {
                bool findNext = false;
                for (int i = 0; i < 8; ++i) {
                    int tx = x + DIRX[i];
                    int ty = y + DIRY[i];
                    if (isValid(tx, ty)) {
                        if (board[tx][ty] == index) {
                            x = tx;
                            y = ty;
                            findNext = true;
                            ++index;
                            break;
                        }
                    }
                }
                if (!findNext) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                bool returnOrigin = false;
                for (int i = 0; i < 8; ++i) {
                    int tx = x + DIRX[i];
                    int ty = y + DIRY[i];
                    if (isValid(tx, ty)) {
                        if (board[tx][ty] == 0) {
                            returnOrigin = true;
                            break;
                        }
                    }
                }
                if (!returnOrigin) {
                    flag = false;
                }
            }
        }
        if (flag) {
            printf("MengJiaozhu:WangHang,let us get married.\n");
        } else {
            printf("WangHang:MengJiaozhu,I miss you.\n");
        }
    }
    return 0;
}
