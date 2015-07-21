#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, a;
int last[MAXN], period[MAXN];
bool failed[MAXN];

int main() {
    scanf("%d", &n);
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        if (last[a] == -1) {
            period[a] = 0;
        } else {
            if (period[a] == 0) {
                period[a] = i - last[a];
            } else {
                if (period[a] != i - last[a]) {
                    failed[a] = true;
                }
            }
        }
        last[a] = i;
    }
    int num = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (last[i] != -1 and not failed[i]) {
            ++num;
        }
    }
    printf("%d\n", num);
    for (int i = 0; i < MAXN; ++i) {
        if (last[i] != -1 and not failed[i]) {
            printf("%d %d\n", i, period[i]);
        }
    }
    return 0;
}
