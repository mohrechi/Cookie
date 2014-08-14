class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        unordered_set<int> hdict;
        for (auto word : dict) {
            int hash = 0;
            for (auto c : word) {
                hash = hash * 131 + c;
            }
            hdict.insert(hash);
        }
        vector<int> hashes(s.size(), 0);
        vector<bool> valid(s.size() + 1, false);
        valid[0] = true;
        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                hashes[j] = hashes[j] * 131 + s[i - 1];
                if (hdict.find(hashes[j]) != hdict.end()) {
                    if (valid[j]) {
                        valid[i] = true;
                    }
                }
            }
        }
        return valid[s.size()];
    }
};
