class Solution {
public:
    int countDigitOne(int n) {
        int num = 0;
        for (long long i = 10; i / 10 <= n; i *= 10) {
            num += n / i * (i / 10);
            if (n % i / (i / 10) == 1) {
                if (i == 10) {
                    ++num;
                } else {
                    num += n % (i / 10) + 1;
                }
            } else if (n % i / (i / 10) > 1) {
                if (i == 10) {
                    ++num;
                } else {
                    num += i / 10;
                }
            }
        }
        return num;
    }
};
