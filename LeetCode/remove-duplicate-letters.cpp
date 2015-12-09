class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        map<char, list<int>> pos;
        for (int i = 0; i < n; ++i) {
            pos[s[i]].push_back(i);
        }
        string ret;
        while (pos.size()) {
            int idx = n;
            for (auto& p : pos) {
                if (idx == n || p.first < s[idx]) {
                    bool valid = true;
                    for (auto& q : pos) {
                        if (p.first != q.first) {
                            if (p.second.front() > q.second.back()) {
                                valid = false;
                                break;
                            }
                        }
                    }
                    if (valid) {
                        idx = p.second.front();
                    }
                }
            }
            ret += s[idx];
            pos.erase(s[idx]);
            for (auto& p : pos) {
                while (p.second.front() < idx) {
                    p.second.pop_front();
                }
            }
        }
        return ret;
    }
};
