class Solution {
public:
    void sortColors(int A[], int n) {
        int first = 0, last = n - 1;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                while (first < i) {
                    if (A[first] != 0) {
                        swap(A[first], A[i]);
                        --i;
                        break;
                    }
                    ++first;
                }
            } else if (A[i] == 2) {
                while (last > i) {
                    if (A[last] != 2) {
                        swap(A[last], A[i]);
                        --i;
                        break;
                    }
                    --last;
                }
            }
        }
    }
};
