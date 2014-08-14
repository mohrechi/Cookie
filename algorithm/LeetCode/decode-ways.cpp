class Solution {
public:
    int numDecodings(string s) {
        int a = 0, b = 1, c = 0;
        for (int i = 0; i < s.length(); ++i) {
            c = 0;
            if (s[i] != '0') {
                c += b;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                c += a;
            }
            a = b;
            b = c;
        }
        return c;
    }
};
