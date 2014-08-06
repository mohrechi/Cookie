class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i;
        for (i = num.size() - 1; i > 0; --i) {
            if (num[i] > num[i - 1]) {
                break;
            }
        }
        if (i == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        reverse(num.begin() + i, num.end());
        int index = num.size() - 1;
        for (int j = num.size() - 2; j >= i; --j) {
            if (num[j] > num[i - 1] && num[j] <= num[index]) {
                index = j;
            }
        }
        swap(num[i - 1], num[index]);
    }
};
