class Solution {
public:
    bool isNumber(const char *s) {
        int state = 0;
        for (int i = 0; s[i]; ++i) {
            switch (state) {
            case 0:
                if (s[i] == ' ') {
                    state = 0;
                } else if (s[i] == '+' || s[i] == '-') {
                    state = 1;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = 2;
                } else if (s[i] == '.') {
                    state = 9;
                } else {
                    return false;
                }
                break;
            case 1:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 2;
                } else if (s[i] == '.') {
                    state = 9;
                } else {
                    return false;
                }
                break;
            case 2:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 2;
                } else if (s[i] == '.') {
                    state = 3;
                } else if (s[i] == 'e') {
                    state = 5;
                } else if (s[i] == ' ') {
                    state = 8;
                } else {
                    return false;
                }
                break;
            case 3:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 4;
                } else if (s[i] == ' ') {
                    state = 8;
                } else if (s[i] == 'e') {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 4:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 4;
                } else if (s[i] == ' ') {
                    state = 8;
                } else if (s[i] == 'e') {
                    state = 5;
                } else {
                    return false;
                }
                break;
            case 5:
                if (s[i] == '+' || s[i] == '-') {
                    state = 6;
                } else if (s[i] >= '0' && s[i] <= '9') {
                    state = 7;
                } else {
                    return false;
                }
                break;
            case 6:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 7;
                } else {
                    return false;
                }
                break;
            case 7:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 7;
                } else if (s[i] == ' ') {
                    state = 8;
                } else {
                    return false;
                }
                break;
            case 8:
                if (s[i] == ' ') {
                    state = 8;
                } else {
                    return false;
                }
                break;
            case 9:
                if (s[i] >= '0' && s[i] <= '9') {
                    state = 4;
                } else {
                    return false;
                }
                break;
            }
        }
        return state == 2 || state == 3 || state == 4 || state == 7 || state == 8;
    }
};
