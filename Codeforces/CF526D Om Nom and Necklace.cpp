#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 100;

int n, k;
string s;
int nextt[MAXN];
bool valid[MAXN];

int main() {
    cin >> n >> k >> s;
    nextt[0] = -1;
    for (int i = 1, j = -1; i <= n; ++i) {
        while (j != -1 && s[i - 1] != s[j]) {
            j = nextt[j];
        }
        nextt[i] = ++j;
        int len = i - nextt[i];
        int num = i / len;
        if (i % len == 0) {
            putchar(num % k <= num / k ? '1' : '0');
        } else {
            putchar(num % k < num / k ? '1' : '0');
        }
    }
    putchar('\n');
    return 0;
}
