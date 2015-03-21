class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool negative = false;
        long long num = numerator;
        long long den = denominator;
        if (num < 0) {
            num = -num;
            negative = !negative;
        }
        if (den < 0) {
            den = -den;
            negative = !negative;
        }
        long long integer = num / den;
        num -= integer * den;
        string output;
        do {
            output = (char)(integer % 10 + '0') + output;
            integer /= 10;
        } while (integer);
        if (negative && (num || output != "0")) {
            output = '-' + output;
        }
        if (!num) {
            return output;
        }
        output += ".";
        vector<int> fractions;
        vector<int> digits;
        while (true) {
            num *= 10;
            for (int i = 0; i < fractions.size(); ++i) {
                if (fractions[i] == num) {
                    for (int j = 0; j < i; ++j) {
                        output += (char)(digits[j] + '0');
                    }
                    output += '(';
                    for (int j = i; j < digits.size(); ++j) {
                        output += (char)(digits[j] + '0');
                    }
                    output += ')';
                    return output;
                }
            }
            fractions.push_back(num);
            digits.push_back(num / den);
            num %= den;
            if (num == 0) {
                for (int j = 0; j < digits.size(); ++j) {
                    output += (char)(digits[j] + '0');
                }
                return output;
            }
        }
    }
};
