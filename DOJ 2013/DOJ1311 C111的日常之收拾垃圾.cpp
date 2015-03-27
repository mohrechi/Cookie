#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000 + 10;

bool valid[MAXN];

int main() {
    int v, n, a;
    while (~scanf("%d%d", &v, &n)) {
        memset(valid, false, sizeof(valid));
        valid[0] = true;
        while (n--) {
            scanf("%d", &a);
            for (int j = v - a; j >= 0; --j) {
                if (valid[j]) {
                    valid[j + a] = true;
                }
            }
        }
        for (int j = v; j >= 0; --j) {
            if (valid[j]) {
                cout << v - j << endl;
                break;
            }
        }
    }
    return 0;
}
