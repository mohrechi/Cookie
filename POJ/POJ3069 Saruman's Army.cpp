#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 5;

int r, n, a[MAXN];

int main() {
    while (scanf("%d%d", &r, &n), r != -1 || n != -1) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int anchor = 0, cnt = 0;
        while (anchor < n) {
            ++cnt;
            for (int i = anchor; i < n; ++i) {
                if (a[i] - a[anchor] > r) {
                    anchor = i - 1;
                    break;
                }
            }
            for (int i = anchor; i <= n; ++i) {
                if (i == n || a[i] - a[anchor] > r) {
                    anchor = i;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
