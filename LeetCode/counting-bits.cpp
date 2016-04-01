class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            if ((i - 1) & 1) {
                for (int j = 1; ; ++j) {
                    if (((i - 1) & (1 << j)) == 0) {
                        bits[i] = bits[i - 1] + 1 - j;
                        break;
                    }
                }
            } else {
                bits[i] = bits[i - 1] + 1;
            }
        }
        return bits;
    }
};
