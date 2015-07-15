#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int INF = 0x7fffffff;

int n, a;
int nums[MAXN];
int steps[MAXN];

int que[MAXN], dist[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a);
        ++nums[a];
        int step = 0;
        bool inc = true;
        while (a) {
            if (inc) {
                int sub = 1;
                for (int b = a << 1; b < MAXN; b <<= 1, ++sub) {
                    ++nums[b];
                    steps[b] += step + sub;
                }
            }
            inc = a & 1;
            a >>= 1;
            ++nums[a];
            steps[a] += ++step;
        }
    }
    int ans = INF;
    for (int i = 0; i < MAXN; ++i) {
        if (nums[i] == n) {
            ans = min(ans, steps[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
