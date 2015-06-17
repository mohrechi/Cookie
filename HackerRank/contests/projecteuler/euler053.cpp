#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 1;

unsigned long long C[MAXN][MAXN];

int main() {
    int N;
    long long K;
    cin >> N >> K;
    for (int i = 0; i <= N; ++i) {
        C[i][0] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (C[i - 1][j - 1] == K + 1 or C[i - 1][j] == K + 1 or
                C[i - 1][j - 1] > K - C[i - 1][j]) {
                C[i][j] = K + 1;
                ++cnt;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
