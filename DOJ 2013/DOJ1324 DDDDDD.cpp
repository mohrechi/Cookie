#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int main() {
    int n, a;
    while (~scanf("%d", &n)) {
        int count = 0, num;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (count == 0) {
                ++count;
                num = a;
            } else if (num == a) {
                ++count;
            } else {
                --count;
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
