#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10;

int digits[MAXN];
int dp[MAXN][10][2];

int get(int x, int pre, int flag, bool limit) {
    if (x < 0) {
        return 1;
    }
    if (!limit && dp[x][pre][flag] != -1) {
        return dp[x][pre][flag];
    }
    int last = limit ? digits[x] : 9;
    long long sum = 0;
    for (int i = 0; i <= last; ++i) {
        if (!flag || abs(i - pre) >= 2) {
            sum += get(x - 1, i, flag || i != 0, limit && (i == last));
        }
    }
    if (!limit) {
        dp[x][pre][flag] = sum;
    }
    return sum;
}

int solve(int x) {
    int len = 0;
    while (x) {
        digits[len++] = x % 10;
        x /= 10;
    }
    return get(len - 1, 0, 0, true);
}

int main() {
    int a, b;
    memset(dp, -1,sizeof(dp));
    scanf("%d%d", &a, &b);
    if (a > b) {
        swap(a, b);
    }
    printf("%d\n", solve(b) - solve(a - 1));
    return 0;
}
