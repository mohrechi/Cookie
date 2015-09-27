#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int n;
int a[MAXN], b[MAXN];
list<int> la, lb;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    bool win = false;
    while (!win) {
        next_permutation(b, b + n);
        bool same = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                same = false;
                break;
            }
        }
        if (same) {
            break;
        }
        la.clear();
        lb.clear();
        for (int i = 0; i < n; ++i) {
            la.push_back(a[i]);
            lb.push_back(b[i]);
        }
        while (la.size() && lb.size()) {
            int ta = la.front();
            int tb = lb.front();
            la.pop_front();
            lb.pop_front();
            if (ta > tb) {
                la.push_back(tb);
                la.push_back(ta);
            } else if (ta < tb) {
                lb.push_back(ta);
                lb.push_back(tb);
            }
        }
        if (lb.size() > 0) {
            win = true;
        }
    }
    if (win) {
        puts("YES");
        for (int i = 0; i < n; ++i) {
            if (i) {
                putchar(' ');
            }
            printf("%d", b[i]);
        }
    } else {
        puts("NO");
    }
    return 0;
}
