class MinStack {
private:
    stack<int> s, mn;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        if (mn.empty() || mn.top() >= x) {
            mn.push(x);
        }
    }
    
    void pop() {
        int t = s.top();
        s.pop();
        if (!mn.empty() && mn.top() == t) {
            mn.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
    }
};