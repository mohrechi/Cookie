class Solution {
public:
    string minWindow(string S, string T) {
        string mini = "";
        vector<int> tCnt(128, 0);
        for (auto c : T) {
            ++tCnt[c];
        }
        int fit = 0;
        for (auto c : tCnt) {
            fit += c == 0;
        }
        int l = 0, r = 0;
        vector<int> sCnt(128, 0);
        for (; r < S.length(); ++r) {
            if (tCnt[S[r]] > 0) {
                if (sCnt[S[r]] == tCnt[S[r]] - 1) {
                    ++fit;
                }
                ++sCnt[S[r]];
            }
            if (fit == 128) {
                for (; l <= r; ++l) {
                    if (tCnt[S[l]] > 0) {
                        if (sCnt[S[l]] == tCnt[S[l]]) {
                            break;
                        }
                        --sCnt[S[l]];
                    }
                }
                if (mini == "" || r - l + 1 < mini.length()) {
                    mini = S.substr(l, r - l + 1);
                }
            }
        }
        return mini;
    }
};
