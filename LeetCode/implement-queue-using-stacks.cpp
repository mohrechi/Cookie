class Queue {
public:
    void push(int x) {
        in.push(x);
    }

    void pop(void) {
        if (out.size() == 0) {
            fetch();
        }
        out.pop();
    }

    int peek(void) {
        if (out.size() == 0) {
            fetch();
        }
        return out.top();
    }

    bool empty(void) {
        return in.size() == 0 and out.size() == 0;
    }
    
private:
    stack<int> in, out;
    
    void fetch() {
        while (in.size() > 0) {
            out.push(in.top());
            in.pop();
        }
    }
};
