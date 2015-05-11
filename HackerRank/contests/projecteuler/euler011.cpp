#include <bits/stdc++.h>
using namespace std;
const int DIR_X[] = {1, 1, 1, 0};
const int DIR_Y[] = {-1, 0, 1, 1};

int main() {
    int grid[20][20];
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            for (int k = 0; k < 4; ++k) {
                int tx = i;
                int ty = j;
                int temp = grid[i][j];
                for (int l = 0; l < 3; ++l) {
                    tx += DIR_X[k];
                    ty += DIR_Y[k];
                    if (tx < 0 or tx >= 20) {
                        temp = 0;
                        break;
                    }
                    if (ty < 0 or ty >= 20) {
                        temp = 0;
                        break;
                    }
                    temp *= grid[tx][ty];
                }
                ans = max(ans, temp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
