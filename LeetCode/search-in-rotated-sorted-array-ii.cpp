class Solution {
public:
    bool search(int A[], int n, int target) {
        int shift = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (A[i] > A[i + 1]) {
                shift = i + 1;
                break;
            }
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A[(mid + shift) % n] == target) {
                return true;
            } else if (A[(mid + shift) % n] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
