#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int PRIME = 177777;

int n[3];
char s[3][MAXN];
unsigned long long h[3][MAXN];

void calcHash(int &n, char s[MAXN], unsigned long long h[MAXN]) {
    unsigned long long p = 1;
    for (n = 1; s[n]; ++n) {
        h[n] = h[n - 1] + s[n] * p;
        p *= PRIME;
    }
    --n;
}

bool contain(int n1, unsigned long long h1[MAXN],
             int n2, unsigned long long h2[MAXN]) {
    unsigned long long p = 1;
    for (int i = 1; i + n2 - 1 <= n1; ++i) {
        if (h1[i + n2 - 1] - h1[i - 1] == h2[n2] * p) {
            return true;
        }
        p *= PRIME;
    }
    return false;
}

int intersect(int n1, unsigned long long h1[MAXN],
              int n2, unsigned long long h2[MAXN]) {
    unsigned long long p = 1;
    for (int i = 1; i < n1 - n2 + 1; ++i) {
        p *= PRIME;
    }
    for (int i = max(1, n1 - n2 + 1); i <= n1; ++i) {
        int len = min(n1 - i + 1, n2);
        if (h1[i + len - 1] - h1[i - 1] == h2[len] * p) {
            return len;
        }
        p *= PRIME;
    }
    return 0;
}

int num, p[3], ans = 1e8;
bool visit[3];

void dfs(int idx) {
    if (idx == num) {
        int len = 0;
        for (int i = 0; i < num; ++i) {
            len += n[i];
            if (i + 1 < num) {
                len -= intersect(n[p[i]], h[p[i]], n[p[i + 1]], h[p[i + 1]]);
            }
        }
        ans = min(ans, len);
        return;
    }
    for (int i = 0; i < num; ++i) {
        if (!visit[i]) {
            visit[i] = true;
            p[idx] = i;
            dfs(idx + 1);
            visit[i] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        scanf("%s", s[i] + 1);
        calcHash(n[i], s[i], h[i]);
    }
    num = 3;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if (i != j) {
                if (n[i] <= n[j]) {
                    if (contain(n[j], h[j], n[i], h[i])) {
                        --num;
                        n[i] = n[num];
                        memcpy(s[i], s[num], sizeof(s[i]));
                        memcpy(h[i], h[num], sizeof(h[i]));
                        --i;
                        break;
                    }
                }
            }
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}
