class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int lp = strlen(p);
        int ls = strlen(s);
        int cnt = 0;
        for (int i = 0; i < lp; ++i) {
            cnt += p[i] != '*';
        }
        if (cnt > ls) {
            return false;
        }
        if (ls == 0) {
            for (int i = 0; i < lp; ++i) {
                if (p[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        vector<int> match[2];
        for (int i = 0; i <= lp; ++i) {
            match[0].push_back(false);
            match[1].push_back(false);
        }
        match[0][0] = true;
        for (int i = 1; i <= lp; ++i) {
            if (match[0][i - 1] && p[i - 1] == '*') {
                match[0][i] = true;
            } else {
                break;
            }
        }
        int curr = 0, prev = 1;
        for (int i = 1; i <= ls; ++i) {
            swap(curr, prev);
            match[curr][0] = false;
            for (int j = 1; j <= lp; ++j) {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    match[curr][j] = match[prev][j - 1];
                } else if (p[j - 1] == '*' && (match[prev][j] || match[curr][j - 1])) {
                    match[curr][j] = true;
                } else {
                    match[curr][j] = false;
                }
            }
        }
        return match[curr][lp];
    }
};
