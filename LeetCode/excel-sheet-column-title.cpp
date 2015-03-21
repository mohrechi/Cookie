class Solution {
public:
    string convertToTitle(int n) {
        string output;
        while (n) {
            --n;
            output = (char)(n % 26 + 'A') + output;
            n /= 26;
        }
        return output;
    }
};
