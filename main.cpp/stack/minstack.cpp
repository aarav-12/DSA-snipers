class MinStack {
    stack<int> s1;  // normal stack
    stack<int> s2;  // keeps track of minimums
public:
    MinStack() { }
    
    void push(int x) {
        s1.push(x);
        // push the smaller of (x or current min) into s2
        if (!s2.empty() && s2.top() < x)
            s2.push(s2.top());
        else
            s2.push(x);
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};
