class Solution {
public:
    string hundredStr(int num){
        vector<string> a = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> b = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string ret;
        ret = num % 100 < 20 ? a[num%100] : b[(num%100)/10] + (num%10 ? " " + a[num%10] : "");
        if (num > 99) {
            ret = a[num/100] + " Hundred" + (num%100 ? " " + ret : "");
        }
        return ret;
    }
    string numberToWords(int num) {
        string ret;
        vector<string> c = {"Thousand", "Million", "Billion"};
        ret = hundredStr(num % 1000);
        for (int i = 0; i < 3; ++i){
            num /= 1000;
            ret = num % 1000 ? hundredStr(num%1000) + " " + c[i] + " " + ret : ret;
        }
        while (ret.back() == ' ') {
            ret.pop_back();
        }
        return ret.empty() ? "Zero" : ret;
    }
};
