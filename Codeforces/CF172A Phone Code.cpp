#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 10;

int n, m;
char c[MAXN], s[MAXN];

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        if (i) {
            gets(s);
            for (int j = 0; j < m; ++j) {
                if (s[j] != c[j]) {
                    m = j;
                    break;
                }
            }
        } else {
            gets(c);
            m = strlen(c);
        }
    }
    cout << m << endl;
    return 0;
}
