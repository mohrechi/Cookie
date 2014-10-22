class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int a = m - 1;
        int b = n - 1;
        int p = m + n - 1;
        while (a >= 0 && b >= 0) {
            if (A[a] > B[b]) {
                A[p--] = A[a--];
            } else {
                A[p--] = B[b--];
            }
        }
        while (a >= 0) {
            A[p--] = A[a--];
        }
        while (b >= 0) {
            A[p--] = B[b--];
        }
    }
};
