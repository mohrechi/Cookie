class Solution {
public:
    bool isPowerOfFour(int num) {
        int x = 1;
        for (int i = 0; i < 16; ++i) {
            if (num == x) {
                return true;
            }
            x <<= 2;
        }
        return false;
    }
};
