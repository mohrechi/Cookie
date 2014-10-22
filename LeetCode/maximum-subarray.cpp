class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ans = A[0];
        for (int i = 1; i < n; ++i) {
            A[i] = max(A[i], A[i] + A[i - 1]);
            ans = max(ans, A[i]);
        }
        return ans;
    }
};
