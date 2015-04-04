class Solution {
public:
    int rob(vector<int> &num) {
        int nonMax = 0, didMax = 0;
        for (auto n : num) {
            int newNonMax = max(nonMax, didMax);
            int newDidMax = max(didMax, nonMax + n);
            nonMax = newNonMax;
            didMax = newDidMax;
        }
        return max(nonMax, didMax);
    }
};