class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = min(1, n);
        bool first = true;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1]) {
                first = true;
                A[m++] = A[i];
            } else {
                if (first) {
                    first = false;
                    A[m++] = A[i];
                }
            }
        }
        return m;
    }
};
