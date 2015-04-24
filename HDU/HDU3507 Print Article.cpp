#include <cstdio>
const int MAXN = 500000 + 10;

int n, m;
int s[MAXN], dp[MAXN], q[MAXN];

inline int getK(const int &i) {
    return s[i];
}

inline int getY(const int &i) {
    return dp[i] + s[i] * s[i];
}

inline int getDy(const int &i, const int &j) {
    return getY(i) - getY(j);
}

inline int getX(const int &i) {
    return s[i] << 1;
}

inline int getDx(const int &i, const int &j) {
    return getX(i) - getX(j);
}

inline int getDp(const int &i, const int &j) {
    return dp[j] + m + (s[i] - s[j]) * (s[i] - s[j]);
}

void convexHull() {
    int front = 0, rear = 1;
    q[0] = 0;
    for (int i = 1; i <= n; ++i) {
        while (front + 1 < rear) {
            if (getDy(q[front + 1], q[front]) <= getK(i) * getDx(q[front + 1], q[front])) {
                ++front;
            } else {
                break;
            }
        }
        dp[i] = getDp(i, q[front]);
        while (front + 1 < rear) {
            if (getDy(i, q[rear - 1]) * getDx(q[rear - 1], q[rear - 2]) <=
                getDx(i, q[rear - 1]) * getDy(q[rear - 1], q[rear - 2])) {
                --rear;
            } else {
                break;
            }
        }
        q[rear++] = i;
    }
}

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &s[i]);
            s[i] += s[i - 1];
        }
        convexHull();
        printf("%d\n", dp[n]);
    }
    return 0;
}
