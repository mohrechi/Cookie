#include <bits/stdc++.h>
using namespace std;
const int MAXS = 10005;

char s[MAXS];

int main() {
    int m, l, r, k;
    gets(s + 1);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d", &l, &r, &k);
        k %= (r - l + 1);
        if (k) {
            reverse(s + l, s + (r - k) + 1);
            reverse(s + (r - k) + 1, s + r + 1);
            reverse(s + l, s + r + 1);
        }
    }
    puts(s + 1);
    return 0;
}
