#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
const int INF = 0x7fffffff;

int T, M, N, S, Q, p[MAXN];
int place[2][MAXN];

int getLessAndEqual(int x) {
    int idx = -1;
    int l = 0, r = M - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (p[mid] <= x) {
            l = mid + 1;
            idx = max(idx, mid);
        } else {
            r = mid - 1;
        }
    }
    return idx;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        scanf("%d%d", &S, &Q);
        memset(p, false, sizeof(p));
        for (int i = 0; i < M; ++i) {
            scanf("%d", &p[i]);
        }
        int minCost = INF;
        int sprinklerNum = 0, expand = 0;
        int curr = 0, pres = 1;
        for (int len = 0; len <= N; ++len) {
            bool possible = true;
            int idx = 1 - len, last = 0, num = 0;
            while (possible) {
                int next = getLessAndEqual(idx + len + len);
                if (p[next] <= last) {
                    possible = false;
                    break;
                }
                place[curr][num++] = p[next];
                if (p[next] + len >= N) {
                    break;
                }
                last = idx;
                idx = p[next] + 1;
            }
            if (possible) {
                int cost = num * S + len * Q;
                if (cost < minCost) {
                    minCost = cost;
                    sprinklerNum = num;
                    expand = len;
                    swap(curr, pres);
                }
                if (num == 1) {
                    break;
                }
            }
        }
        printf("%d %d\n", sprinklerNum, expand);
        for (int i = 0; i < sprinklerNum; ++i) {
            if (i) {
                putchar(' ');
            }
            printf("%d", place[pres][i]);
        }
        putchar('\n');
    }
    return 0;
}
