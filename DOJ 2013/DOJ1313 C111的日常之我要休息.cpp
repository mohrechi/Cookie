#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;

enum {FREE, ACTIVE};

bool have[MAXN];
int nextStart[MAXN];

struct Contest {
    int start;
    int length;
} contests[MAXN];

int dp[MAXN];
map<int, vector<int> > indexes;

int main() {
    int n, k, p, t;
    while (cin >> n >> k) {
        ++n;
        indexes.clear();
        memset(have, false, sizeof(have));
        for (int i = 0; i < k; ++i) {
            scanf("%d%d", &contests[i].start, &contests[i].length);
            if (contests[i].start < 1) {
                contests[i].length -= 1 - contests[i].start;
                contests[i].start = 1;
            }
            if (contests[i].start + contests[i].length > n) {
                contests[i].length = n - contests[i].start;
            }
            if (contests[i].start < n) {
                have[contests[i].start] = true;
                indexes[contests[i].start].push_back(i);
            }
        }
        int cur = n;
        for (int i = n; i >= 1; --i) {
            if (have[i]) {
                cur = i;
            }
            nextStart[i] = cur;
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[nextStart[1]] = 0;
        for (map<int, vector<int> >::iterator it = indexes.begin(); it != indexes.end(); ++it) {
            int start = dp[it->first];
            for (int i = 0; i < it->second.size(); ++i) {
                Contest &contest = contests[it->second[i]];
                int end = contest.start + contest.length;
                dp[nextStart[end]] = min(dp[nextStart[end]], start + contest.length);
            }
        }
        cout << n - dp[n] - 1 << endl;
    }
    return 0;
}
