class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        for (int i = 4; i < n; i += 2) {
            isPrime[i] = false;
        }
        for (int i = 3; i < n; i += 2) {
            int inc = i << 1;
            for (int j = i + inc; j < n; j += inc) {
                isPrime[j] = false;
            }
        }
        int cnt = n > 2;
        for (int i = 3; i < n; i += 2) {
            cnt += isPrime[i];
        }
        return cnt;
    }
};