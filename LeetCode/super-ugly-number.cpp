class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = 0;
        vector<int> nums(n, 1);
        vector<int> idxs(primes.size(), 0);
        while (len < n - 1) {
            int next = INT_MAX;
            for (int i = 0; i < (int)primes.size(); ++i) {
                while (primes[i] * nums[idxs[i]] <= nums[len]) {
                    ++idxs[i];
                }
                next = min(next, primes[i] * nums[idxs[i]]);
            }
            nums[++len] = next;
        }
        return nums[n - 1];
    }
};
