class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (mid * mid == num) {
                return true;
            }
            if (num / mid > mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
