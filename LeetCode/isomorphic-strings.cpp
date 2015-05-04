class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return single(s, t) and single(t, s);
    }
private:
    bool single(const string &s, const string &t) {
        map<char, char> sub;
        for (int i = 0; i < (int)s.length(); ++i) {
            if (sub.find(s[i]) == sub.end()) {
                sub[s[i]] = t[i];
            } else {
                if (sub[s[i]] != t[i]) {
                    return false;
                }
            }
        }
    }
};