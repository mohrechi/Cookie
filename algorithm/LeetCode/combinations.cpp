class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> ret;
        for (int i = 0; i < (1 << n); ++i) {
            if (countOne(i) == k) {
                ret.push_back(vector<int>());
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        (*ret.rbegin()).push_back(j + 1);
                    }
                }
            }
        }
        return ret;
    }
private:
    int countOne(int x) {
        int cnt = 0;
        while (x) {
            x = x & (x - 1);
            ++cnt;
        }
        return cnt;
    }
};
