#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    map<int, int> forward;
    map<int, int> backward;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        forward[a] = b;
        backward[b] = a;
    }
    list<int> even;
    list<int> odd;
    set<int> visit;
    int idx = 0;
    while (forward.find(idx) != forward.end()) {
        idx = forward[idx];
        visit.insert(idx);
        if (idx == 0) {
            break;
        }
        even.push_back(idx);
    }
    for (auto it : backward) {
        if (visit.find(it.first) == visit.end()) {
            idx = it.first;
            while (backward.find(idx) != backward.end()) {
                idx = backward[idx];
            }
            break;
        }
    }
    odd.push_back(idx);
    while (forward.find(idx) != forward.end()) {
        idx = forward[idx];
        if (idx == 0) {
            break;
        }
        odd.push_back(idx);
    }
    while (not even.empty() or not odd.empty()) {
        if (not odd.empty()) {
            printf("%d ", odd.front());
            odd.pop_front();
        }
        if (not even.empty()) {
            printf("%d ", even.front());
            even.pop_front();
        }
    }
    putchar('\n');
    return 0;
}
