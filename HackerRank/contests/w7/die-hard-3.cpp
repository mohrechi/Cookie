#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e3 + 10;

int a, b, c;
bool visit[MAXN][MAXN];

bool search(int ca, int cb) {
    int t;
    if (!visit[ca][cb]) {
        visit[ca][cb] = true;
        if (ca == c || cb == c) {
            return true;
        }
        if (search(0, cb)) {
            return true;
        }
        if (search(ca, 0)) {
            return true;
        }
        if (search(a, cb)) {
            return true;
        }
        if (search(ca, b)) {
            return true;
        }
        t = min(ca, b - cb);
        if (search(ca - t, cb + t)) {
            return true;
        }
        t = min(a - ca, cb);
        if (search(ca + t, cb - t)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        memset(visit, false, sizeof(visit));
        puts(search(0, 0) ? "YES" : "NO");
    }
    return 0;
}
