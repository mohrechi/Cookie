class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for (auto& word : words) {
            int bit = 0;
            for (auto c : word) {
                bit |= 1 << (c - 'a');
            }
            bits.push_back(bit);
        }
        int maxVal = 0;
        int n = bits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bits[i] & bits[j]) == 0) {
                    maxVal = max(maxVal, (int)(words[i].length() * words[j].length()));
                }
            }
        }
        return maxVal;
    }
};
