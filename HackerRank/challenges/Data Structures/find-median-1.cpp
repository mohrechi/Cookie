#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    multiset<int, greater<int>> sb;
    multiset<int> ss;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if (ss.size() == 0 || a <= *ss.begin()) {
            sb.insert(a);
            if (sb.size() >= ss.size() + 2) {
                ss.insert(*sb.begin());
                sb.erase(sb.begin());
            }
        } else {
            ss.insert(a);
            if (ss.size() > sb.size()) {
                sb.insert(*ss.begin());
                ss.erase(ss.begin());
            }
        }
        if (i & 1) {
            printf("%d.0\n", *sb.begin());
        } else {
            printf("%.1f\n", ((*sb.begin()) + (*ss.begin())) * 0.5);
        }
    }
    return 0;
}
