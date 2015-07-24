#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;

char a[MAXN], b[MAXN];

void getMini(char *s, int l, int r) {
    if ((r - l) & 1) {
        return;
    }
    int len = (r - l) / 2;
    int mid = l + len;
    getMini(s, l, mid);
    getMini(s, mid, r);
    bool larger = false;
    for (int i = 0; i < len; ++i) {
        if (s[l + i] > s[mid + i]) {
            larger = true;
            break;
        } else if (s[l + i] < s[mid + i]) {
            break;
        }
    }
    if (larger) {
        for (int i = 0; i < len; ++i) {
            swap(s[l + i], s[mid + i]);
        }
    }
}

int main() {
    gets(a);
    gets(b);
    int n = strlen(a);
    getMini(a, 0, n);
    getMini(b, 0, n);
    puts(strcmp(a, b) ? "NO" : "YES");
    return 0;
}
