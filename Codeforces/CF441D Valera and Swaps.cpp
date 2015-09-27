#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 5;

int n, m;
int a[MAXN];
bool visit[MAXN];

struct Loop {
    set<int> s;
    bool operator <(const Loop &loop) const {
        return *s.begin() < *loop.s.begin();
    }
};

Loop getLoop(int p) {
    Loop loop;
    while (!visit[p]) {
        visit[p] = true;
        loop.s.insert(p);
        p = a[p];
    }
    return loop;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    set<Loop> loops;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            loops.insert(getLoop(i));
        }
    }
    int num = n - loops.size();
    vector<pair<int, int>> ans;
    if (num < m) {
        auto first = loops.begin();
        auto it = loops.begin();
        for (int i = 0; i < m - num; ++i) {
            ans.push_back({*(first->s.begin()), *((++it)->s.begin())});
        }
    } else if (num > m) {
        for (int i = 0; i < num - m; ++i) {
            while (loops.begin()->s.size() <= 1) {
                loops.erase(loops.begin());
            }
            auto loop = loops.begin();
            int p = *(loop->s.begin());
            int s = *(++loop->s.begin());
            ans.push_back({p, s});
            swap(a[p], a[s]);
            for (auto c : loop->s) {
                visit[c] = false;
            }
            loops.erase(loops.begin());
            loops.insert(getLoop(p));
            loops.insert(getLoop(s));
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto a : ans) {
        printf("%d %d\n", a.first, a.second);
    }
    return 0;
}
