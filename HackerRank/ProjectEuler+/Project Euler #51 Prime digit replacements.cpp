#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 10;

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

int N, K, L;
struct Node {
    int digit[10];
    bool solid[10];
    int nums[10], num;

    int gen(int x) {
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ret = ret * 10 + (solid[i] ? digit[i] : x);
        }
        return ret;
    }

    bool operator <(const Node &node) const {
        for (int i = 0; i < num; ++i) {
            if (nums[i] < node.nums[i]) {
                return true;
            }
            if (nums[i] > node.nums[i]) {
                return false;
            }
        }
        return false;
    }

    friend ostream& operator <<(ostream& out, const Node &node) {
        for (int i = 0; i < L; ++i) {
            if (i) {
                out << ' ';
            }
            out << node.nums[i];
        }
        return out;
    }
} temp, ans;

void dfs(int n, int k) {
    if (k > K) {
        return;
    }
    if (n == N) {
        if (k == K) {
            temp.num = 0;
            for (int i = (temp.solid[0] ? 0 : 1); i <= 9; ++i) {
                int x = temp.gen(i);
                if (isPrime[x]) {
                    temp.nums[temp.num++] = x;
                    if (temp.num >= L) {
                        ans = min(ans, temp);
                        break;
                    }
                }
            }
        }
        return;
    }
    temp.solid[n] = false;
    dfs(n + 1, k + 1);
    temp.solid[n] = true;
    for (int i = (n == 0 ? 1 : 0); i <= 9; ++i) {
        temp.digit[n] = i;
        dfs(n + 1, k);
    }
}

int main() {
    cin >> N >> K >> L;
    initPrime();
    ans.nums[0] = MAXN;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
