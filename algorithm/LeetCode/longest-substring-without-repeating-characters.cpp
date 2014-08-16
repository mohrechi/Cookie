class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> cnt(128, 0);
        int ans = 0;
        int l = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s[i]];
            while (cnt[s[i]] > 1) {
                --cnt[s[l++]];
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
