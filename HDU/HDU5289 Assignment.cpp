#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;

int n, k, a[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        multiset<int> s;
        long long ans = 0;
        int left = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            s.insert(a[i]);
            while (*s.rbegin() - *s.begin() >= k) {
                s.erase(s.find(a[left++]));
            }
            ans += s.size();
        }
        cout << ans << endl;
    }
    return 0;
}
