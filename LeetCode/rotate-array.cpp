class Solution {
public:
    void reverse(int nums[], int l, int r) {
        for (int i = l; i <= ((l + r) >> 1); ++i) {
            swap(nums[i], nums[r - i + l]);
        }
    }
    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
};
