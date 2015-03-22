class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for (uint32_t i = 0; (1LL << i) <= n; ++i) {
            if ((1LL << i) & n) {
                ++num;
            }
        }
        return num;
    }
};
