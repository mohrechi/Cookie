#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;

int n, num[2][MAXN];

int findNext(int num[MAXN], int idx, int s) {
    if (num[n] - num[idx - 1] < s) {
        return -1;
    }
    int l = idx, r = n, ret = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        int val = num[mid] - num[idx - 1];
        if (val >= s) {
            r = mid - 1;
            if (val == s) {
                ret = min(ret, mid);
            }
        } else {
            l = mid + 1;
        }
    }
    return ret;
}

int main() {
    int a;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        num[0][i] = num[0][i - 1] + (a == 1);
        num[1][i] = num[1][i - 1] + (a == 2);
    }
    vector<pair<int, int>> ans;
    for (int s = 1; s <= n; ++s) {
        int idx = 1, winA = 0, winB = 0, last;
        while (idx <= n) {
            int nextA = findNext(num[0], idx, s);
            int nextB = findNext(num[1], idx, s);
            if (nextA == -1 && nextB == -1) {
                winA = winB = 0;
                break;
            }
            if (nextA == -1) {
                ++winB;
                last = 1;
                idx = nextB + 1;
            } else if (nextB == -1) {
                ++winA;
                last = 0;
                idx = nextA + 1;
            } else if (nextA < nextB) {
                ++winA;
                last = 0;
                idx = nextA + 1;
            } else {
                ++winB;
                last = 1;
                idx = nextB + 1;
            }
        }
        if (winA != winB) {
            if ((winA > winB && last == 0) || (winA < winB && last == 1)) {
                ans.push_back({max(winA, winB), s});
            }
        }
    }
    printf("%d\n", (int)ans.size());
    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        printf("%d %d\n", a.first, a.second);
    }
    return 0;
}
