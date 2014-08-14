class Solution {
public:
    int minCut(string s) {
        vector<int> cuts(s.length());
        vector<int> hashes(s.length(), 0);
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j <= i; ++j) {
                hashes[j] = hashes[j] * 131 + s[i];
            }
            int hash = 0;
            cuts[i] = i + 1;
            for (int j = i; j >= 0; --j) {
                hash = hash * 131 + s[j];
                if (hash == hashes[j]) {
                    if (j == 0) {
                        cuts[i] = 0;
                    } else {
                        cuts[i] = min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
        return *cuts.rbegin();
    }
};
