class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        bool parsingNum = false;
        s += " ";
        int num;
        for (auto c : s) {
            if (parsingNum) {
                if ('0' <= c and c <= '9') {
                    num = num * 10 + c - '0';
                } else {
                    while (ops.size() > 0 and (ops.top() == '+' or ops.top() == '-')) {
                        int t = nums.top() + num;
                        if (ops.top() == '-') {
                            t = nums.top() - num;
                        }
                        ops.pop();
                        nums.pop();
                        num = t;
                    }
                    nums.push(num);
                    parsingNum = false;
                }
            }
            if (not parsingNum) {
                if (c == '(' or c == '+' or c == '-') {
                    ops.push(c);
                } else if (c == ')') {
                    ops.pop();
                    while (ops.size() > 0 and (ops.top() == '+' or ops.top() == '-')) {
                        int t2 = nums.top();
                        nums.pop();
                        int t1 = nums.top();
                        nums.pop();
                        int t = t1 + t2;
                        if (ops.top() == '-') {
                            t = t1 - t2;
                        }
                        ops.pop();
                        nums.push(t);
                    }
                } else if ('0' <= c and c <= '9') {
                    parsingNum = true;
                    num = c - '0';
                }
            }
        }
        return nums.top();
    }
};
