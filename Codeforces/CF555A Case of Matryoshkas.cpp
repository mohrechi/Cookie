#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

vector<vector<int>> chains(MAXN);
vector<int> freei(MAXN);
vector<int> index(MAXN);
vector<int> pos(MAXN);

int main() {
    int n, m, mi, a;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> mi;
        for (int j = 0; j < mi; ++j) {
            cin >> a;
            index[a] = i;
            pos[a] = chains[i].size();
            chains[i].push_back(a);
        }
        freei[i] = chains[i].size();
        if (freei[i] == 1) {
            freei[i] = 0;
        }
    }
    int ans = 0;
    bool stable = pos[1] == 0;
    for (int i = 1; i <= n; ++i) {
        if (stable and index[i] == index[1] and pos[i] == (i - 1)) {
            continue;
        } else {
            stable = false;
        }
        while (pos[i] < freei[index[i]]) {
            if (--freei[index[i]] == 1) {
                freei[index[i]] = 0;
            }
            ++ans;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}
