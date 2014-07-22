#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

int n, a[MAXN];

int main() {
    int mex = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        mex ^= a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > (mex ^ a[i])) {
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
