#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n;
bool choice[MAXN];

int main() {
    int a, b;
    scanf("%d", &n);
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        int sumT = sumA + a;
        if (abs(sumT - sumB) <= 500) {
            sumA += a;
        } else {
            sumB += b;
            choice[i] = true;
        }
    }
    if (abs(sumA - sumB) > 500) {
        puts("-1");
    } else {
        for (int i = 0; i < n; ++i) {
            putchar(choice[i] ? 'G' : 'A');
        }
        putchar('\n');
    }
    return 0;
}
