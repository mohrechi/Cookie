#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;

int n, k;
int a[MAXN];

int main() {
    int num = 1;
    map<int, int> cnt;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = 1, r = 1;
    int maxL = 1, maxR = 1;
    ++cnt[a[1]];
    while (r != n) {
        while (r < n) {
            ++cnt[a[++r]];
            if (cnt[a[r]] == 1) {
                if (++num > k) {
                    break;
                }
            }
            if (maxR - maxL < r - l) {
                maxL = l;
                maxR = r;
            }
        }
        while (l < r) {
            if (--cnt[a[l++]] == 0) {
                --num;
                break;
            }
        }
        if (maxR - maxL < r - l) {
            maxL = l;
            maxR = r;
        }
    }
    printf("%d %d\n", maxL, maxR);
    return 0;
}
