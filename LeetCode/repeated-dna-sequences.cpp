class Solution {
public:
    int encode(string& sub) {
        int hash = 0;
        for (int i = 0; i < sub.length(); ++i) {
            hash *= 4;
            switch (sub[i]) {
            case 'A':
                break;
            case 'C':
                hash += 1;
                break;
            case 'G':
                hash += 2;
                break;
            case 'T':
                hash += 3;
                break;
            }
        }
        return hash;
    }
    string decode(int hash) {
        string sub;
        for (int i = 0; i < 10; ++i) {
            switch (hash % 4) {
            case 0:
                sub = 'A' + sub;
                break;
            case 1:
                sub = 'C' + sub;
                break;
            case 2:
                sub = 'G' + sub;
                break;
            case 3:
                sub = 'T' + sub;
                break;
            }
            hash /= 4;
        }
        return sub;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> hashes;
        for (int i = 0; i <= (int)s.length() - 10; ++i) {
            string sub = s.substr(i, 10);
            ++hashes[encode(sub)];
        }
        vector<string> ans;
        for (auto hash : hashes) {
            if (hash.second > 1) {
                ans.push_back(decode(hash.first));
            }
        }
        return ans;
    }
};
