#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300000 + 10;

int n, m;
char s[MAXN];

int main() {
    int pos;
    char sub[2];
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '.' && s[i + 1] == '.') {
            ++num;
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%s", &pos, sub);
        if (s[pos] == '.' && sub[0] != '.') {
            if (pos - 1 >= 1 && s[pos - 1] == '.') {
                --num;
            }
            if (pos + 1 <= n && s[pos + 1] == '.') {
                --num;
            }
        } else if (s[pos] != '.' && sub[0] == '.') {
            if (pos - 1 >= 1 && s[pos - 1] == '.') {
                ++num;
            }
            if (pos + 1 <= n && s[pos + 1] == '.') {
                ++num;
            }
        }
        s[pos] = sub[0];
        printf("%d\n", num);
    }
    return 0;
}
