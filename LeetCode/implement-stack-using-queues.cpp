class Stack {
public:
    queue<int> q;

    void push(int x) {
        int num = q.size();
        q.push(x);
        while (num--) {
            x = q.front();
            q.pop();
            q.push(x);
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
