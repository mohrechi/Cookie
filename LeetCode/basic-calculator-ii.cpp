class Solution {
public:
    int calculate(string s) {
        stack<char> ops;
        stack<int> nums;
        s += ' ';
        bool parsingNum = false;
        int num;
        for (auto c : s) {
            if (parsingNum) {
                if ('0' <= c and c <= '9') {
                    num = num * 10 + c - '0';
                } else {
                    parsingNum = false;
                    nums.push(num);
                    reduce(ops, nums, Degree::ONE);
                }
            }
            if (not parsingNum) {
                if ('0' <= c and c <= '9') {
                    num = c - '0';
                    parsingNum = true;
                } else if (c == '+' or c == '-') {
                    reduce(ops, nums, Degree::TWO);
                    ops.push(c);
                } else if (c == '*' or c == '/') {
                    reduce(ops, nums, Degree::ONE);
                    ops.push(c);
                }
            }
        }
        reduce(ops, nums, Degree::TWO);
        return nums.top();
    }

private:
    enum class Degree {
        TWO, ONE
    };

    void reduce(stack<char> &ops, stack<int> &nums, Degree degree) {
        while (ops.size() > 0) {
            char op = ops.top();
            if (degree == Degree::ONE) {
                if (op == '+' or op == '-') {
                    break;
                }
            }
            ops.pop();
            int t2 = nums.top();
            nums.pop();
            int t1 = nums.top();
            nums.pop();
            int t;
            switch (op) {
                case '+': t = t1 + t2; break;
                case '-': t = t1 - t2; break;
                case '*': t = t1 * t2; break;
                case '/': t = t1 / t2; break;
            }
            nums.push(t);
        }
    }
};
