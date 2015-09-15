#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;

int n;
struct Len {
    int idx, len;
    bool operator <(const Len& l) const {
        return len > l.len;
    }
} l[MAXN];

int code[MAXN];
char ans[MAXN][MAXN];

void mov(char s[MAXN], int code[MAXN], int len) {
    for (int i = 0; i < len; ++i) {
        s[i] = code[i] + '0';
    }
    s[len] = 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        l[i].idx = i;
        scanf("%d", &l[i].len);
    }
    sort(l, l + n);
    bool possible = true;
    mov(ans[l[0].idx], code, l[0].len);
    for (int i = 1; i < n; ++i) {
        int carry = 1;
        for (int j = l[i].len - 1; j >= 0; --j) {
            code[j] += carry;
            if (code[j] == 2) {
                code[j] = 0;
                carry = 1;
            } else {
                carry = 0;
                break;
            }
        }
        if (carry) {
            possible = false;
            break;
        }
        mov(ans[l[i].idx], code, l[i].len);
    }
    if (possible) {
        puts("YES");
        for (int i = 0; i < n; ++i) {
            puts(ans[i]);
        }
    } else {
        puts("NO");
    }
    return 0;
}
