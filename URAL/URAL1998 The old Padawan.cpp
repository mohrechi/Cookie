#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, k;
int w[MAXN], t[MAXN];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w[i]);
        if (i) {
            w[i] += w[i - 1];
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &t[i]);
    }
    t[m] = 0x3f3f3f3f;
    int time = 0;
    for (int i = 0, j = 0; i < n && j <= m; ++j) {
        int acc = t[j] - time - 1;
        if (i + acc >= n) {
            time += n - i;
            break;
        }
        time += acc + 1;
        i += acc;
        int left = 1, right = i;
        int index = 0;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (w[i - 1] - w[mid - 1] > k) {
                index = max(index, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        i = index;
    }
    printf("%d\n", time);
    return 0;
}
