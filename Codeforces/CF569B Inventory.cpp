#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, a[MAXN];
bool visit[MAXN], invalid[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] < 1 || n < a[i]) {
            invalid[i] = true;
        } else {
            if (visit[a[i]]) {
                invalid[i] = true;
            } else {
                visit[a[i]] = true;
            }
        }
    }
    for (int i = 1, j = 1; i <= n; ++i) {
        if (invalid[i]) {
            while (visit[j]) {
                ++j;
            }
            a[i] = j++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    puts("");
    return 0;
}
