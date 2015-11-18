class Solution {
public:
    bool isAdditiveNumber(string num) {
        list<int> a;
        for (int i = 0; i < (int)num.length() - 1; ++i) {
            a.push_front(num[i] - '0');
            if ((int)a.size() == 2) {
                if (*a.begin() == 0 && *a.rbegin() == 0) {
                    break;
                }
            }
            list<int> b;
            for (int j = i + 1; j < (int)num.length(); ++j) {
                b.push_front(num[j] - '0');
                if ((int)b.size() == 2) {
                    if (*b.begin() == 0 && *b.rbegin() == 0) {
                        break;
                    }
                }
                if (isAdditiveNumber(num, j + 1, 2, a, b)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool isAdditiveNumber(const string& num, int idx, int cnt, const list<int>& a, const list<int>& b) {
        if (idx == (int)num.length()) {
            return cnt >= 3;
        }
        list<int> c;
        auto ai = a.begin();
        auto bi = b.begin();
        int carry = 0;
        while (ai != a.end() || bi != b.end()) {
            int val = 0;
            if (ai != a.end() && bi != b.end()) {
                val = *ai + *bi + carry;
                ++ai, ++bi;
            } else if (ai != a.end()) {
                val = *ai + carry;
                ++ai;
            } else {
                val = *bi + carry;
                ++bi;
            }
            if (val >= 10) {
                val -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            c.push_back(val);
        }
        if (carry) {
            c.push_back(1);
        }
        if ((int)num.length() - idx < (int)c.size()) {
            return false;
        }
        auto ci = c.rbegin();
        for (int i = 0; i < (int)c.size(); ++i, ++ci) {
            if (num[idx + i] - '0' != *ci) {
                return false;
            }
        }
        return isAdditiveNumber(num, idx + (int)c.size(), cnt + 1, b, c);
    }
};
