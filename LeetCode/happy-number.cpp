class Solution {
public:
    bool isHappy(int n) {
        if (n == 0) {
            return true;
        }
        set<int> nums;
        nums.insert(n);
        while (n != 1) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if (nums.find(sum) != nums.end()) {
                return false;
            }
            nums.insert(sum);
            n = sum;
        }
        return true;
    }
};