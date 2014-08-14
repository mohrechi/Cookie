class Solution {
public:
    int divide(int dividend, int divisor) {
        int ret = 0;
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        bool positive = (dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0);
        long long c[64];
        c[0] = b;
        for (int i = 1; i < 33; ++i) {
            c[i] = c[i - 1] << 1;
        }
        int i = 0;
        while ((1LL << i) <= a) {
            ++i;
        }
        while (--i >= 0) {
            if (a >= c[i]) {
                a -= c[i];
                ret += 1LL << i;
            }
        }
        return positive ? ret : -ret;
    }
};
