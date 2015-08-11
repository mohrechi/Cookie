#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int n;
char s[MAXN];
int sum[MAXN];

bool isVowel(char ch) {
    return ch == 'I' || ch == 'E' || ch == 'A' ||
           ch == 'O' || ch == 'U' || ch == 'Y';
}

int main() {
    scanf("%s", s + 1);
    for (n = 1; s[n]; ++n) {
        sum[n] = sum[n - 1] + isVowel(s[n]);
    }
    --n;
    double ans = 0.0;
    double cur = 0.0;
    for (int i = 1; i <= (n + 1) / 2; ++i) {
        cur += sum[n - i + 1] - sum[i - 1];
        if (i * 2 - 1 == n) {
            ans += cur / i;
        } else {
            ans += cur / i;
            ans += cur / (n - i + 1);
        }
    }
    printf("%.8f\n", ans);
    return 0;
}
