#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 5;

int n, l, p;
struct Stop {
    int d, f;
    bool operator <(const Stop &stop) const {
        if (f == stop.f) {
            return d < stop.d;
        }
        return f < stop.f;
    }
} stop[MAXN];

bool compare(const Stop &a, const Stop &b) {
    return a.d > b.d;
}

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &stop[i].d, &stop[i].f);
        }
        sort(stop, stop + n, compare);
        scanf("%d%d", &l, &p);
        int cnt = 0, idx = 0;
        priority_queue<Stop> q;
        l -= p;
        while (l > 0) {
            while (idx < n && stop[idx].d >= l) {
                q.push(stop[idx++]);
            }
            if (q.size() == 0) {
                cnt = -1;
                break;
            }
            ++cnt;
            l -= q.top().f;
            q.pop();
        }
        printf("%d\n", cnt);
    }
    return 0;
}
