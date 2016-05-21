#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;

int fact[10];
int depth[MAXN], length[MAXN];

int dfs(int x, int d) {
    if (length[x]) {
        return length[x];
    }
    if (depth[x]) {
        return -(length[x] = d - depth[x]);
    }
    depth[x] = d;
    int next = 0, t = x;
    while (t) {
        next += fact[t % 10];
        t /= 10;
    }
    if (x == 0) {
        next = 1;
    }
    t = dfs(next, d + 1);
    if (length[x]) {
        return length[x];
    }
    if (t < 0) {
        length[x] = -t;
        return t;
    }
    return length[x] = t + 1;
}

int main() {
    int T, N, L;
    fact[0] = 1;
    for (int i = 1; i <= 9; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    ios::sync_with_stdio(false);
    cin >> T;
    int last = 0;
    while (T--) {
        cin >> N >> L;
        for (; last <= N; ++last) {
            dfs(last, 1);
        }
        bool first = true;
        for (int i = 0; i <= N; ++i) {
            if (length[i] == L) {
                if (first) {
                    first = false;
                } else {
                    cout << ' ';
                }
                cout << i;
            }
        }
        if (first) {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}
