#include <cstdio>

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 1) {
            return find(A, m, B, n, (total >> 1) + 1);
        }
        return (find(A, m, B, n, total >> 1) + find(A, m, B, n, (total >> 1) + 1)) * 0.5;
    }
private:
    double find(int a[], int m, int b[], int n, int k) {
        if (m > n) {
            return find(b, n, a, m, k);
        }
        if (m == 0) {
            return b[k - 1];
        }
        if (k == 1) {
            return min(a[0], b[0]);
        }
        int ka = min(k >> 1, m);
        int kb = k - ka;
        if (a[ka - 1] < b[kb - 1]) {
            return find(a + ka, m - ka, b, n, k - ka);
        }
        if (a[ka - 1] > b[kb - 1]) {
            return find(a, m, b + kb, n - kb, k - kb);
        }
        return a[ka - 1];
    }
};

int main() {
    return 0;
}
