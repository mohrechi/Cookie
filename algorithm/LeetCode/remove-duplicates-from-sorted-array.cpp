class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int m = min(1, n);
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1]) {
                A[m++] = A[i];
            }
        }
        return m;
    }
};
