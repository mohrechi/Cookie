#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000 + 10;

int N, K;
bool isPrime[MAXN];

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i < MAXN; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXN; i += 2) {
        if (isPrime[i]) {
            int inc = i << 1;
            for (int j = i + inc; j < MAXN; j += inc) {
                isPrime[j] = false;
            }
        }
    }
}

struct Node {
    int val, inc;
    bool operator <(const Node& node) const {
        if (val == node.val) {
            return inc < node.inc;
        }
        return val < node.val;
    }
};

bool visit[MAXN];

set<int> perms;
int digit[10], digitNum;
bool used[10];

void getPerms(int d, int x) {
    if (d == digitNum) {
        visit[x] = true;
        if (isPrime[x]) {
            perms.insert(x);
        }
    } else {
        for (int i = 0; i < digitNum; ++i) {
            if (not used[i]) {
                if (d == 0 and digit[i] == 0) {
                    continue;
                }
                used[i] = true;
                getPerms(d + 1, x * 10 + digit[i]);
                used[i] = false;
            }
        }
    }
}

bool isValid(int val, int inc, int d) {
    if (d == K - 2) {
        return true;
    }
    if (perms.find(val + inc) == perms.end()) {
        return false;
    }
    return isValid(val + inc, inc, d + 1);
}

int main() {
    cin >> N >> K;
    initPrime();
    vector<Node> ans;
    for (int i = 1000; i < N; ++i) {
        if (not visit[i]) {
            int t = i;
            digitNum = 0;
            while (t) {
                digit[digitNum++] = t % 10;
                t /= 10;
            }
            perms.clear();
            getPerms(0, 0);
            for (auto perm : perms) {
                visit[perm] = true;
            }
            for (auto a : perms) {
                if (a >= N) {
                    break;
                }
                for (auto b : perms) {
                    if (a < b) {
                        if (isValid(b, b - a, 0)) {
                            ans.push_back({a, b - a});
                        }
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        for (int i = 0; i < K; ++i) {
            cout << a.val;
            a.val += a.inc;
        }
        cout << endl;
    }
    return 0;
}
