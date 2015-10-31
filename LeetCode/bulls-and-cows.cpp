class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0, b = 0;
        int sNum[10] = {0};
        int gNum[10] = {0};
        for (int i = 0; i < (int)secret.size(); ++i) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g) {
                ++a;
            } else {
                if (sNum[g]) {
                    --sNum[g];
                    ++b;
                } else {
                    ++gNum[g];
                }
                if (gNum[s]) {
                    --gNum[s];
                    ++b;
                } else {
                    ++sNum[s];
                }
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
