class Solution {
public:
    int count(int n, int f) {
        int num = 0;
        for (long long i = f; i <= n; i *= f) {
            num += n / i;
        }
        return num;
    }
    int trailingZeroes(int n) {
        return min(count(n, 2), count(n, 5));
    }
};
