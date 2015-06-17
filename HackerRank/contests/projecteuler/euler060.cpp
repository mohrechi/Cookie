#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000000 + 20;
const int MAXK = 5 + 10;
const int MAXP = 2262 + 10;

int N, K;
bool isPrime[MAXN];
int prime[MAXP], primeNum;
bool valid[MAXP][MAXP];
vector<vector<int>> nex(MAXP);

int powMod(long long x, int n, long long mod) {
    long long ans = 1, t = x;
    while (n) {
        if (n & 1) {
            ans = ans * t % mod;
        }
        t = t * t % mod;
        n >>= 1;
    }
    return (int)ans;
}

bool millerRabin(long long n) {
    for (int i = 0; i < 4; ++i) {
        int x = rand() % (n - 4) + 2;
        int t = powMod(x, n - 1, n);
        if (t != 1) {
            return false;
        }
    }
    return true;
}

bool checkPrime(long long x) {
    if (x < MAXN) {
        return isPrime[x];
    }
    return millerRabin(x);
}

int nums[MAXK];
multiset<int> ans;

long long concat(long long x, long long y) {
    if (y >= 10000) return x * 100000 + y;
    if (y >= 1000) return x * 10000 + y;
    if (y >= 100) return x * 1000 + y;
    if (y >= 10) return x * 100 + y;
    return x * 10 + y;
}

void dfs(int depth) {
    if (depth == K) {
        int sum = 0;
        for (int i = 0; i < K; ++i) {
            sum += prime[nums[i]];
        }
        ans.insert(sum);
        return;
    }
    if (depth == 0) {
        for (int i = 0; i < primeNum; ++i) {
            for (int j = 0; j < (int)nex[i].size(); ++j) {
                nums[0] = i;
                nums[1] = nex[i][j];
                dfs(2);
            }
        }
    } else {
        for (int i = 0; i < (int)nex[nums[depth - 1]].size(); ++i) {
            bool flag = true;
            for (int j = 0; j < depth; ++j) {
                if (not valid[nums[j]][nex[nums[depth - 1]][i]]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                nums[depth] = nex[nums[depth - 1]][i];
                dfs(depth + 1);
            }
        }
    }
}

int main() {
    cin >> N >> K;
    primeNum = 1;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 4; i < MAXN; i += 2) {
        isPrime[i] = false;
    }
    prime[0] = 2;
    for (int i = 3; i < MAXN; i += 2) {
        if (isPrime[i]) {
            if (i < N) {
                prime[primeNum++] = i;
            }
            int inc = i << 1;
            for (int j = i + inc; j < MAXN; j += inc) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i < primeNum; ++i) {
        for (int j = i + 1; j < primeNum; ++j) {
            if (checkPrime(concat(prime[i], prime[j])) and
                checkPrime(concat(prime[j], prime[i]))) {
                nex[i].push_back(j);
                valid[i][j] = valid[j][i] = true;
            }
        }
    }
    dfs(0);
    for (auto a : ans) {
        cout << a << endl;
    }
    return 0;
}
