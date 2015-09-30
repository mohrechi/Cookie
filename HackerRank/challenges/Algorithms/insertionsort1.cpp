#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;

int main() {
    int s, v[MAXN];
    cin >> s;
    for (int i = 0; i < s; ++i) {
        scanf("%d", &v[i]);
    }
    int last = v[s - 1];
    int i;
    for (i = s - 2; i >= -1; --i) {
        if (i >= 0 && v[i] > last) {
            v[i + 1] = v[i];
        } else {
            v[i + 1] = last;
            i = -2;
        }
        for (int j = 0; j < s; ++j) {
            if (j) {
                putchar(' ');
            }
            printf("%d", v[j]);
        }
        putchar('\n');
    }
    return 0;
}
