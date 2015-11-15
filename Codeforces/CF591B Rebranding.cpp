#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;

char s[MAXN];

int main() {
    int n, m;
    char sub[128], pos[128];
    char a[2], b[2];
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for (int i = 'a'; i <= 'z'; ++i) {
        sub[i] = i;
        pos[i] = i;
    }
    while (m--) {
        scanf("%s%s", a, b);
        swap(sub[pos[a[0]]], sub[pos[b[0]]]);
        swap(pos[a[0]], pos[b[0]]);
    }
    for (int i = 0; s[i]; ++i) {
        s[i] = sub[s[i]];
    }
    puts(s);
    return 0;
}
