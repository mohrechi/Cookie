class Solution {
public:
    int reverse(int x) {
        bool positive = true;
        if (x < 0) {
            positive = false;
            x = -x;
        }
        int y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return positive ? y : -y;
    }
};
