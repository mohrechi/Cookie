class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        if (L.size() == 0) {
            return ret;
        }
        map<int, int> strMap;
        vector<int> dictCnt(L.size(), 0);
        for (int i = 0; i < L.size(); ++i) {
            strMap[getHash(L[i])] = i;
        }
        for (int i = 0; i < L.size(); ++i) {
            ++dictCnt[strMap[getHash(L[i])]];
        }
        int zero = 0;
        for (int i = 0; i < L.size(); ++i) {
            zero += dictCnt[i] == 0;
        }
        int len = L[0].length();
        vector<int> hashes;
        for (int i = 0; i <= (int)S.length() - len; ++i) {
            hashes.push_back(getHash(S.substr(i, len)));
            if (strMap.find(hashes[i]) != strMap.end()) {
                hashes[i] = strMap[hashes[i]];
            } else {
                hashes[i] = -1;
            }
        }
        for (int i = 0; i < len; ++i) {
            vector<int> cnt(L.size(), 0);
            int nonZero = zero;
            for (int j = i; j <= (int)S.length() - len; j += len) {
                if (hashes[j] != -1) {
                    if (cnt[hashes[j]] == dictCnt[hashes[j]] - 1) {
                        ++nonZero;
                    }
                    ++cnt[hashes[j]];
                }
                if ((j - i) / len >= L.size()) {
                    int first = j - L.size() * len;
                    if (hashes[first] != -1) {
                        if (cnt[hashes[first]] == dictCnt[hashes[first]]) {
                            --nonZero;
                        }
                        --cnt[hashes[first]];
                    }
                }
                if (nonZero == L.size()) {
                    ret.push_back(j - (L.size() - 1) * len);
                }
            }
        }
        return ret;
    }
private:
    int getHash(string s) {
        int hash = 0;
        for (int i = 0; i < s.length(); ++i) {
            hash = hash * 131 + s[i];
        }
        return hash;
    }
};
