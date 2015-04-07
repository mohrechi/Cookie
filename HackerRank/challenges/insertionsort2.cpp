#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int main() {
    int s, a[MAXN];
    cin >> s;
    for (int i = 0; i < s; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < s; ++i) {
        for (int j = i; j >= 1; --j) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
        for (int j = 0; j < s; ++j) {
            if (j) {
                putchar(' ');
            }
            printf("%d", a[j]);
        }
        putchar('\n');
    }
    return 0;
}
