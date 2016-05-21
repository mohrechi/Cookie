#include <bits/stdc++.h>
using namespace std;

string getDigit(char ch) {
    switch (ch) {
    case '0': return "Zero";
    case '1': return "One";
    case '2': return "Two";
    case '3': return "Three";
    case '4': return "Four";
    case '5': return "Five";
    case '6': return "Six";
    case '7': return "Seven";
    case '8': return "Eight";
    case '9': return "Nine";
    }
    return "";
}

string getDigit1x(char ch) {
    switch (ch) {
    case '0': return "Ten";
    case '1': return "Eleven";
    case '2': return "Twelve";
    case '3': return "Thirteen";
    case '4': return "Fourteen";
    case '5': return "Fifteen";
    case '6': return "Sixteen";
    case '7': return "Seventeen";
    case '8': return "Eighteen";
    case '9': return "Nineteen";
    }
    return "";
}

string getDigit10(char ch) {
    switch (ch) {
    case '2': return "Twenty";
    case '3': return "Thirty";
    case '4': return "Forty";
    case '5': return "Fifty";
    case '6': return "Sixty";
    case '7': return "Seventy";
    case '8': return "Eighty";
    case '9': return "Ninety";
    }
    return "";
}

string getDigits(string s) {
    string ret = "";
    int len = s.length();
    if (len == 3) {
        if (s[len - 3] != '0') {
            ret += getDigit(s[len - 3]) + " Hundred";
        }
    }
    if (len >= 2) {
        if (s[len - 2] != '0') {
            if (ret.length() > 0) {
                ret += ' ';
            }
            if (s[len - 2] == '1') {
                ret += getDigit1x(s[len - 1]);
            } else {
                ret += getDigit10(s[len - 2]);
            }
        }
    }
    if (s[len - 1] != '0' and not (len >= 2 and s[len - 2] == '1')) {
        if (ret.length() > 0) {
            ret += ' ';
        }
        ret += getDigit(s[len - 1]);
    }
    return ret;
}

string getAmount(int x) {
    switch (x) {
    case 1: return "Thousand";
    case 2: return "Million";
    case 3: return "Billion";
    }
    return "";
}

int main() {
    int T;
    string N;
    cin >> T;
    while (T--) {
        cin >> N;
        if (N == "0") {
            cout << "Zero" << endl;
        } else {
            string ans = "";
            int len = N.length();
            for (int i = len - 3, j = 0; ; i -= 3, ++j) {
                int index = max(i, 0);
                string sub = getDigits(N.substr(index, i + 3 - index));
                if (sub.length() > 0) {
                    if (ans.length() > 0) {
                        ans = " " + ans;
                    }
                    string am = getAmount(j);
                    if (am.length() > 0) {
                        sub = sub + " " + am;
                    }
                    ans = sub + ans;
                }
                if (i <= 0) {
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
