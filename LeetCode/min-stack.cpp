class MinStack {
public:
    void push(int x) {
        values.push_back(x);
        mins.push_back(x);
        if (mins.size() > 1) {
            if (mins[mins.size() - 1] > mins[mins.size() - 2]) {
                mins[mins.size() - 1] = mins[mins.size() - 2];
            }
        }
    }

    void pop() {
        values.pop_back();
        mins.pop_back();
    }

    int top() {
        return values[values.size() - 1];
    }

    int getMin() {
        return mins[mins.size() - 1];
    }
private:
    vector<int> values;
    vector<int> mins;
};
