class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int l = 0, r = num.size() - 1;
        while (true) {
            int mid = (l + r) >> 1;
            if (mid < num.size() - 1 && num[mid] < num[mid + 1]) {
                l = mid + 1;
            } else if (mid > 0 && num[mid] < num[mid - 1]) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
    }
};
