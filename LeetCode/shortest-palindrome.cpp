class Solution {
public:
    string shortestPalindrome(string s) {
        string ss = "#";
        for (auto c : s) {
            ss += c;
            ss += '#';
        }
        int n = ss.length();
        int mx = 0, id = 0;
        vector<int> p(n, 0);
        for (int i = 0; i < n; ++i) {
            if (mx > i) {
                p[i] = min(p[(id << 1) - i], mx - i);
            } else {
                p[i] = 1;
            }
            while (ss[i + p[i]] == ss[i - p[i]] and i - p[i] >= 0 and i + p[i] < n) {
                ++p[i];
            }
            if (p[i] + i > mx) {
                mx = p[i] + i;
                id = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == i + 1) {
                ans = i;
            }
        }
        s = "";
        for (int i = (int)ss.length() - 1; i > ans; --i) {
            if (ss[i] != '#') {
                s += ss[i];
            }
        }
        for (int i = ans; i < (int)ss.length(); ++i) {
            if (ss[i] != '#') {
                s += ss[i];
            }
        }
        return s;
    }
};
