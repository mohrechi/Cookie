#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXM = 46350;

long long P, B, N;

struct Reminder {
    long long rem, num;
    bool operator <(const Reminder& reminder) const {
        if (rem == reminder.rem) {
            return num < reminder.num;
        }
        return rem < reminder.rem;
    }
} rem[MAXM];

long long fastPow(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = ret * x % P;
        }
        x = x * x % P;
    }
    return ret;
}

int main() {
    while (scanf("%I64d%I64d%I64d", &P, &B, &N) != EOF) {
        long long S = sqrt((double)P);
        for (int i = 0; i < S; ++i) {
            rem[i].num = i;
            rem[i].rem = fastPow(B, i);
        }
        sort(rem, rem + S);
        long long ans = -1;
        for (int i = S; i >= 0; --i) {
            long long remain = fastPow(B, i * S) * N % P;
            int l = 0, r = S - 1;
            ans = S;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (rem[mid].rem >= remain) {
                    r = mid - 1;
                    if (rem[mid].rem == remain) {
                        ans = min(ans, (long long)mid);
                    }
                } else {
                    l = mid + 1;
                }
            }
            if (ans != S) {
                ans = P - 1 - i * S + rem[ans].num;
                break;
            }
            ans = -1;
        }
        if (ans == -1) {
            puts("no solution");
        } else {
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
