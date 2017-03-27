#include <bits/stdc++.h>
using namespace std;
const int MAXN = 7000 + 5;

enum State {
    Win = 1, Lose = -1, Loop = 0
};

int n, k[2];
int s[MAXN][2];
State states[MAXN][2];
bool visited[MAXN][2];
int cnt[MAXN][2];
int front, rear, q[MAXN * 2][2];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> k[0];
    for (int i = 0; i < k[0]; ++i) {
        cin >> s[i][0];
    }
    cin >> k[1];
    for (int i = 0; i < k[1]; ++i) {
        cin >> s[i][1];
    }
    states[0][0] = states[0][1] = Lose;
    visited[0][0] = visited[0][1] = true;
    front = 0, rear = 2;
    q[0][0] = 0, q[0][1] = 0;
    q[1][0] = 0, q[1][1] = 1;
    while (front < rear) {
        int pos = q[front][0];
        int turn = q[front++][1];
        for (int i = 0; i < k[1 - turn]; ++i) {
            int prev = (pos - s[i][1 - turn] + n) % n;
            if (states[pos][turn] == Lose) {
                states[prev][1 - turn] = Win;
            } else if (states[pos][turn] == Win) {
                if (++cnt[prev][1 - turn] == k[1 - turn]) {
                    states[prev][1 - turn] = Lose;
                } else {
                    continue;
                }
            }
            if (!visited[prev][1 - turn]) {
                visited[prev][1 - turn] = true;
                q[rear][0] = prev;
                q[rear++][1] = 1 - turn;
            }
        }
    }
    for (int j = 0; j < 2; ++j) {
        for (int i = 1; i < n; ++i) {
            switch (states[i][j]) {
            case Win:
                cout << "Win ";
                break;
            case Lose:
                cout << "Lose ";
                break;
            default:
                cout << "Loop ";
            }
        }
        cout << endl;
    }
    return 0;
}
