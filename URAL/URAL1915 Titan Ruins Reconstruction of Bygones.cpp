#include <cstdio>
const int MAXN = 1e6 + 1e5;
// Visual C++ 2010
int stack[MAXN * 2], top;

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x > 0) {
            stack[top++] = x;
        } else if (x < 0) {
            printf("%d\n", stack[--top]);
        } else {
            if (top < n - i) {
                for (int i = 0; i < top; ++i) {
                    stack[i + top] = stack[i];
                }
                top <<= 1;
            }
        }
    }
    return 0;
}
