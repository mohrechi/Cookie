class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) {
                A[m++] = A[i];
            }
        }
        for (int i = 0; i < m; ++i) {
            if (abs(A[i]) <= m) {
                A[abs(A[i]) - 1] = -abs(A[abs(A[i]) - 1]);
            }
        }
        for (int i = 0; i < m; ++i) {
            if (A[i] > 0) {
                return i + 1;
            }
        }
        return m + 1;
    }
};
