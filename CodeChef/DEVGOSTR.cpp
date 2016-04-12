#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 3;
const int MAX_S = 50 + 1;

char path[MAX_S];
vector<string> valid[MAX_A][MAX_S];

void dfs(int idx, int bound) {
    valid[bound][idx].push_back(path);
    if (idx >= MAX_S) {
        return;
    }
    for (int i = 0; i < MAX_A; ++i) {
        bool flag = true;
        for (int j = idx - 2; j >= 0; j -= 2) {
            if ((i + 'a') == path[j]) {
                int mid = (idx + j) >> 1;
                if (path[j] == path[mid]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            path[idx] = i + 'a';
            dfs(idx + 1, max(bound, i));
            path[idx] = 0;
        }
    }
}

char s[MAX_S];

int main() {
    int T, A, K;
    scanf("%d", &T);
    dfs(0, 0);
    while (T--) {
        scanf("%d%d%s", &A, &K, s);
        int n = strlen(s), cnt = 0;
        for (int i = 0; i < A; ++i) {
            for (auto& c : valid[i][n]) {
                int diff = 0;
                for (int j = 0; j < n; ++j) {
                    diff += c[j] != s[j];
                }
                if (diff <= K) {
                    ++cnt;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
