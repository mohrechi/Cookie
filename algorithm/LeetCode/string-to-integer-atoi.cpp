class Solution {
public:
    int atoi(const char *str) {
        const char *INT_MAX_STR = "2147483647";
        const char *INT_MIN_STR = "2147483648";
        int numsNum = 0, num = 0;
        char nums[20];
        bool positive = true;
        int state = 0;
        for (int i = 0; str[i] && state != 4; ++i) {
            char ch = str[i];
            switch (state) {
            case 0:
                if (ch == ' ') {
                    state = 0;
                } else if (ch == '+') {
                    state = 1;
                } else if (ch == '-') {
                    positive = false;
                    state = 1;
                } else if (ch >= '0' && ch <= '9') {
                    state = 2;
                    nums[numsNum++] = ch;
                } else {
                    return 0;
                }
                break;
            case 1:
                if (ch >= '0' && ch <= '9') {
                    state = 2;
                    nums[numsNum++] = ch;
                } else {
                    return 0;
                }
                break;
            case 2:
                if (ch >= '0' && ch <= '9') {
                    nums[numsNum++] = ch;
                } else {
                    state = 4;
                }
                break;
            }
        }
        if (numsNum > 10) {
            if (positive) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        } else if (numsNum == 10) {
            if (positive) {
                for (int i = 0; i < 10; ++i) {
                    if (nums[i] > INT_MAX_STR[i]) {
                        return INT_MAX;
                    } else if (nums[i] < INT_MAX_STR[i]) {
                        break;
                    }
                }
            } else {
                for (int i = 0; i < 10; ++i) {
                    if (nums[i] > INT_MIN_STR[i]) {
                        return INT_MIN;
                    } else if (nums[i] < INT_MIN_STR[i]) {
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < numsNum; ++i) {
            num *= 10;
            if (positive) {
                num += nums[i] - '0';
            } else {
                num -= nums[i] - '0';
            }
        }
        return num;
    }
};
