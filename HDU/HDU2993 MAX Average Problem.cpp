#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

int n, k;
__int64 s[MAXN];
int q[MAXN];

inline int getNextInt() {
    char ch = getchar();
    while (ch < '0' || '9' < ch) {
        ch = getchar();
    }
    int ret = 0;
    while ('0' <= ch && ch <= '9') {
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}

inline int dy(int x, int y) {
    return s[x] - s[y];
}

inline int dx(int x, int y) {
    return x - y;
}

inline bool useless(int a, int b, int c) {
    return dy(c, b) * dx(b, a) <= dy(b, a) * dx(c, b);
}

int main() {
    while (~scanf("%d%d", &n, &k)) {
        for (int i = 1; i <= n; ++i) {
            s[i] = getNextInt();
            s[i] += s[i - 1];
        }
        int front = 0, rear = 1;
        double ans = 0;
        for (int i = k; i <= n; ++i) {
            while (front < rear - 1 && useless(q[rear - 2], q[rear - 1], i - k)) {
                --rear;
            }
            q[rear++] = i - k;
            while (front < rear - 1 && useless(q[front + 1], q[front], i)) {
                ++front;
            }
            ans = max(ans, (double)dy(i, q[front]) / dx(i, q[front]));
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
