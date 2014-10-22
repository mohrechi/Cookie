class Solution {
public:
    string addBinary(string a, string b) {
        string c;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        bool carry = false;
        for (int i = 0; i < max(a.length(), b.length()); ++i) {
            int temp = carry;
            if (i < a.length()) {
                if (a[i] == '1') {
                    ++temp;
                }
            }
            if (i < b.length()) {
                if (b[i] == '1') {
                    ++temp;
                }
            }
            switch (temp) {
            case 0:
                c += "0";
                carry = false;
                break;
            case 1:
                c += "1";
                carry = false;
                break;
            case 2:
                c += "0";
                carry = true;
                break;
            case 3:
                c += "1";
                carry = true;
                break;
            }
        }
        if (carry) {
            c += "1";
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
