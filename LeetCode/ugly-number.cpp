class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) {
            return false;
        }
        static int fact[] = {2, 3, 5};
        for (int i = 0; i < 3; ++i) {
            while (num % fact[i] == 0) {
                num /= fact[i];
            }
        }
        return num == 1;
    }
};
