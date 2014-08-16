class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        string ret;
        for (int i = 0; i < nRows; ++i) {
            for (int j = 0; j < s.length(); ++j) {
                int k = j % ((nRows << 1) - 2);
                if (k < nRows) {
                    if (k == i) {
                        ret += s[j];
                    }
                } else {
                    if (k - nRows == nRows - i - 2) {
                        ret += s[j];
                    }
                }
            }
        }
        return ret;
    }
};
