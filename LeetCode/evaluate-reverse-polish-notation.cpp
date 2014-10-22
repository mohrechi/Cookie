class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int top = 0;
        vector<int> vals(tokens.size());
        for (auto token : tokens) {
            if (token == "+") {
                vals[top - 2] += vals[top - 1];
                --top;
            } else if (token == "-") {
                vals[top - 2] -= vals[top - 1];
                --top;
            } else if (token == "*") {
                vals[top - 2] *= vals[top - 1];
                --top;
            } else if (token == "/") {
                vals[top - 2] /= vals[top - 1];
                --top;
            } else {
                stringstream ss(token);
                ss >> vals[top];
                ++top;
            }
        }
        return vals[0];
    }
};
