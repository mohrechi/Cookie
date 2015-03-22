class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0, majority;
        for (auto n : num) {
            if (count == 0 || majority == n) {
                majority = n;
                ++count;
            } else {
                --count;
            }
        }
        return majority;
    }
};
