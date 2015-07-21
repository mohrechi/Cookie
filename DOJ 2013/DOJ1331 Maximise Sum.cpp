#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

long long t, n, m;
long long a, sum;

long long fastRead() {
    char ch;
    while (true) {
        ch = getchar();
        if ('0' <= ch and ch <= '9') {
            break;
        }
    }
    long long num = ch - '0';
    while (true) {
        ch = getchar();
        if ('0' <= ch and ch <= '9') {
            num = num * 10 + ch - '0';
        } else {
            break;
        }
    }
    return num;
}

int main() {
    t = fastRead();
    while (t--) {
        n = fastRead();
        m = fastRead();
        sum = 0;
        long long ans = 0;
        set<long long> s;
        s.insert(0);
        while (n--) {
            a = fastRead();
            a %= m;
            sum = (sum + a) % m;
            set<long long>::iterator t = s.upper_bound(sum);
            if (t != s.end()) {
                ans = max(ans, sum - *t + m);
            } else {
                ans = max(ans, sum);
            }
            s.insert(sum);
        }
        cout << ans << endl;
    }
    return 0;
}
