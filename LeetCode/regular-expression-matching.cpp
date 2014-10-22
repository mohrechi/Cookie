class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int ls = strlen(s);
        int lp = 0;
        for (int i = 0; p[i]; ++i) {
            if (p[i] != '*') {
                ++lp;
            }
        }
        if (lp == 0) {
            return ls == 0;
        }
        vector<char> np(lp, 0);
        vector<char> repeat(lp, 0);
        for (int i = 0, j = 0; p[i]; ++i) {
            if (p[i] == '*') {
                repeat[j - 1] = p[i - 1];
                np[j - 1] = '*';
            } else {
                np[j++] = p[i];
            }
        }
        vector<vector<bool>> match(ls + 1, vector<bool>(lp + 1, false));
        match[0][0] = true;
        for (int j = 1; j <= lp; ++j) {
            if (np[j - 1] == '*') {
                match[0][j] = match[0][j - 1];
            } else {
                break;
            }
        }
        for (int i = 1; i <= ls; ++i) {
            for (int j = 1; j <= lp; ++j) {
                if (np[j - 1] == '.' || np[j - 1] == s[i - 1]) {
                    match[i][j] = match[i - 1][j - 1];
                } else if (np[j - 1] == '*') {
                    match[i][j] = match[i][j - 1] || (match[i - 1][j] && (repeat[j - 1] == '.' || repeat[j - 1] == s[i - 1]));
                } else {
                    match[i][j] = false;
                }
            }
        }
        return match[ls][lp];
    }
};
