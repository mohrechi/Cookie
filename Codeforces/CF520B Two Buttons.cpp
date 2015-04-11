#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l;
    while (cin >> n >> m) {
        queue<int> q;
        vector<int> len(max(n, m * 2) + 10, 0x3f3f3f3f);
        vector<bool> visit(max(n, m * 2) + 10, false);
        q.push(n);
        len[n] = 0;
        visit[n] = true;
        while (!q.empty()) {
            n = q.front();
            if (n == m) {
                cout << len[n] << endl;
                break;
            }
            if ((n << 1) < len.size() && len[n << 1] > len[n] + 1) {
                len[n << 1] = len[n] + 1;
                if (!visit[n << 1]) {
                    visit[n << 1] = true;
                    q.push(n << 1);
                }
            }
            if (n - 1 >= 0 && len[n - 1] > len[n] + 1) {
                len[n - 1] = len[n] + 1;
                if (!visit[n - 1]) {
                    visit[n - 1] = true;
                    q.push(n - 1);
                }
            }
            visit[n] = false;
            q.pop();
        }
    }
    return 0;
}
