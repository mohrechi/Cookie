#include <bits/stdc++.h>
using namespace std;

long long dfs(long long h, long long n, bool l) {
    if (h == 1) {
        return 0;
    }
    long long half = 1LL << (h - 2);
    long long sub = 1LL << (h - 1);
    long long next = n >= half ? n - half : n;
    if ((n < half) ^ l) {
        return sub + dfs(h - 1, next, l);
    }
    return 1 + dfs(h - 1, next, not l);
}

int main() {
    long long h, n;
    ios::sync_with_stdio(false);
    while (cin >> h >> n) {
        cout << dfs(h + 1, n - 1, true) << endl;
    }
    return 0;
}
