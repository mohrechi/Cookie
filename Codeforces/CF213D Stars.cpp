#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);

int main() {
    int n;
    double d = 20 * sin(PI * 0.3);
    double t = d / 2 - 5;
    double x[] = {0, d - t, d / 2, t};
    double y[] = {0, -sqrt(100 - t * t), 10 * cos(PI * 0.3), y[1]};
    scanf("%d", &n);
    printf("%d\n", 4 * n + 1);
    for (int i = 0; i < 4 * n + 1; ++i) {
        printf("%.10f %.10f\n", x[i % 4], y[i % 4]);
        x[i % 4] += d;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d %d\n", 1 + 4 * i, 3 + 4 * i , 5 + 4 * i , 2 + 4 * i , 4 + 4 * i);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d %d ", 1 + 4 * i , 2 + 4 * i , 3 + 4 * i , 4 + 4 * i);
    }
    for (int i = 0; i < n + 1; ++i) {
        printf("%d ", 4 * (n - i) + 1);
    }
    putchar('\n');
    return 0;
}
