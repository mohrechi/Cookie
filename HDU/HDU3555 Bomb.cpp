#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 20;

int digits[MAXN];
__int64 dp[MAXN][10][2];

__int64 get(int x, int pre, int flag, int limit) {
    if (x < 0) {
        return flag;
    }
    if (!limit && dp[x][pre][flag] != -1) {
        return dp[x][pre][flag];
    }
    int last = limit ? digits[x] : 9;
    __int64 sum = 0;
    for (int i = 0; i <= last; ++i) {
        sum += get(x - 1, i, flag || (pre == 4 && i == 9), limit && (i == last));
    }
    if (!limit) {
        dp[x][pre][flag] = sum;
    }
    return sum;
}

__int64 solve(__int64 n) {
    int len = 0;
    while (n) {
        digits[len++] = n % 10;
        n /= 10;
    }
    return get(len - 1, 0, 0, 1);
}

int main() {
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--) {
        __int64 n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
