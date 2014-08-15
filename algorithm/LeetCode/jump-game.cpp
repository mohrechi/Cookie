class Solution {
public:
    int jump(int A[], int n) {
        int last = 0, ret = 0, in = 0;
        for (int i = 0; i < n; ++i) {
            if (i > in) {
                in = last;
                ++ret;
            }
            last = max(last, i + A[i]);
        }
        return ret;
    }
};
