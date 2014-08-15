class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1 << n;
        vector<int> ret(size);
        for (int i = 0; i < size; ++i) {
            ret[i] = i ^ (i >> 1);
        }
        return ret;
    }
};
