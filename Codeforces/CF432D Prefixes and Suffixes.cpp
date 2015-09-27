#include <bits/stdc++.h>
using namespace std;
const int MAXS = 1e5 + 5;

int fail[MAXS], cnt[MAXS];
char s[MAXS];

void getFail(const char *s) {
    fail[0] = -1;
    for (int i = 1, j = -1; s[i]; ++i) {
        while (j != -1 && s[j + 1] != s[i]) {
            j = fail[j];
        }
        if (s[j + 1] == s[i]) {
            ++j;
        }
        fail[i] = j;
    }
}

int main() {
    scanf("%s", s);
    getFail(s);
    int n = strlen(s);
    for (int i = 0; i <= n; ++i) {
        cnt[i] = 1;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (fail[i] >= 0) {
            cnt[fail[i]] += cnt[i];
        }
    }
    stack<pair<int, int>> stk;
    for (int i = n - 1; i != -1; i = fail[i]) {
        stk.push({i + 1, cnt[i]});
    }
    printf("%d\n", (int)stk.size());
    while (!stk.empty()) {
        auto& it = stk.top();
        printf("%d %d\n", it.first, it.second);
        stk.pop();
    }
    return 0;
}
