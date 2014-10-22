class Solution {
public:
    int sqrt(int x) {
        long long l = 0, r = x;
        long long ret = 0;
        while (l <= r) {
            long long m = (l + r) >> 1;
            if (m * m == x) {
                return m;
            } else if (m * m < x) {
                ret = max(ret, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ret;
    }
};
