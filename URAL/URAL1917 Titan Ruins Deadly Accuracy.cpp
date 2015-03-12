#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int n, p;
int a[MAXN];

int main() {
    while (~scanf("%d%d", &n, &p)) {
        int coinNum = 0, spellNum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        a[n] = 0x3f3f3f3f;
        int last = 0, lastSpell = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < a[i + 1]) {
                if ((i - last + 1) * a[i] <= p) {
                    lastSpell = i;
                    coinNum = i + 1;
                } else {
                    if (lastSpell == -1) {
                        break;
                    } else {
                        i = lastSpell;
                        last = i + 1;
                        ++spellNum;
                        lastSpell = -1;
                    }
                }
            }
        }
        spellNum += lastSpell != -1;
        printf("%d %d\n", coinNum, spellNum);
    }
    return 0;
}
