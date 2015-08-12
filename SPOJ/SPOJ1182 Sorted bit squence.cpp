#include <bits/stdc++.h>
using namespace std;

int c[32][32];

int countNum(unsigned int x, int k) {
    int bits[32], bitNum = 0;
    while (x) {
        bits[bitNum++] = x & 1;
        x >>= 1;
    }
    int num = 0, cnt = 0;
    for (int i = bitNum - 1; i >= 0; --i) {
        if (bits[i] == 1) {
            if (i >= k - cnt) {
                num += c[i][k - cnt];
            }
            if (++cnt > k) {
                break;
            }
        }
        if (i == 0 && cnt == k) {
            ++num;
        }
    }
    return num;
}

int countNum(unsigned int x, unsigned int y, int k) {
    if (x == 0) {
        return countNum(y, k);
    }
    return countNum(y, k) - countNum(x - 1, k);
}

int main() {
    int T, n, m, k;
    scanf("%d", &T);
    for (int i = 0; i < 32; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        unsigned int un = n;
        unsigned int um = m;
        int oneNum;
        for (oneNum = 0; oneNum < 32; ++oneNum) {
            int num = countNum(un, um, oneNum);
            if (k <= num) {
                break;
            }
            k -= num;
        }
        unsigned long long l = un;
        unsigned long long r = um;
        unsigned int ans = um;
        while (l <= r) {
            unsigned int mid = (l + r) / 2;
            int num = countNum(un, mid, oneNum);
            if (num >= k) {
                r = mid - 1;
                if (num == k) {
                    ans = min(ans, mid);
                }
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
