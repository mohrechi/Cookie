class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        string m = "$#";
        for (auto c : s) {
            m += c;
            m += "#";
        }
        m += "%";
        vector<int> p(m.size(), 0);
        int mx = 0, id;
        for (int i = 1; i < p.size() - 1; ++i) {
            if (mx > i) {
                p[i] = min(p[2 * id - i], mx - i);
            } else {
                p[i] = 1;
            }
            for (; m[i + p[i]] == m[i - p[i]]; ++p[i]);
            if (p[i] + i > mx) {
                mx = p[i] + i;
                id = i;
            }
        }
        int ans = 2;
        for (int i = 3; i < p.size(); ++i) {
            if (p[i] > p[ans]) {
                ans = i;
            }
        }
        string palin = m.substr(ans - p[ans] + 1, p[ans] * 2 - 1);
        string ret;
        for (int i = 0; i < palin.size(); ++i) {
            if (palin[i] != '#') {
                ret += palin[i];
            }
        }
        return ret;
    }
};
