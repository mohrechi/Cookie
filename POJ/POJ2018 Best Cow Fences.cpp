#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n, f;
int s[MAXN], q[MAXN];

inline int getDy(const int &i, const int &j) {
    return s[i] - s[j];
}

inline int getDx(const int &i, const int &j) {
    return i - j;
}

inline double getDp(const int &i, const int &j) {
    return (double)(s[i] - s[j]) / (i - j);
}

double convexHull() {
    int front = 0, rear = 1;
    double maxVal = 0.0;
    q[0] = 0;
    for (int i = f; i <= n; ++i) {
        while (front + 1 < rear) {
            if (getDy(q[front + 1], q[front]) * getDx(i, q[front + 1]) <=
                getDx(q[front + 1], q[front]) * getDy(i, q[front + 1])) {
                ++front;
            } else {
                break;
            }
        }
        maxVal = max(maxVal, getDp(i, q[front]));
        while (front + 1 < rear) {
            if (getDy(i - f + 1, q[rear - 1]) * getDx(q[rear - 1], q[rear - 2]) <=
                getDx(i - f + 1, q[rear - 1]) * getDy(q[rear - 1], q[rear - 2])) {
                --rear;
            } else {
                break;
            }
        }
        q[rear++] = i - f + 1;
    }
    return maxVal;
}

int main() {
    while (~scanf("%d%d", &n, &f)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &s[i]);
            s[i] += s[i - 1];
        }
        printf("%d\n", (int)(convexHull() * 1000));
    }
    return 0;
}
