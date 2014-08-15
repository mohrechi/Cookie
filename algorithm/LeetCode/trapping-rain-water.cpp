class Solution {
public:
    int trap(int A[], int n) {
        vector<int> h(n, 0);
        int m = 0;
        for (int i = 0; i < n; ++i) {
            m = max(m, A[i]);
            h[i] = max(h[i], m);
        }
        m = 0;
        for (int i = n - 1; i >= 0; --i) {
            m = max(m, A[i]);
            h[i] = min(h[i], m);
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += h[i] - A[i];
        }
        return sum;
    }
};
