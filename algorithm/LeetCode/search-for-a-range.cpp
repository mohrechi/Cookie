class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int left = -1, right = n;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m] < target) {
                left = max(left, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (A[m] > target) {
                right = min(right, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (A[left + 1] != target || A[right - 1] != target) {
            return {-1, -1};
        }
        return {left + 1, right - 1};
    }
};
