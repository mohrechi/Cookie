class Solution {
public:
    string getPermutation(int n, int k) {
        vector<bool> visit(n + 1, false);
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i - 1] * i;
        }
        string seq;
        k = (k - 1) % fact[n];
        for (int i = n - 1; i >= 0; --i) {
            int pos = k / fact[i], cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if (!visit[j]) {
                    if (cnt == pos) {
                        visit[j] = true;
                        seq += '0' + j;
                        break;
                    }
                    ++cnt;
                }
            }
            k %= fact[i];
        }
        return seq;
    }
};
