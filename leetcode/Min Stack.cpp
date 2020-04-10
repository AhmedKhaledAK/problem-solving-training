class MinStack {
private:
    vector<int> stack;
    vector<int> minstack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if (!minstack.empty()) {
            if (minstack[minstack.size()-1] >= x) {
                minstack.push_back(x);
            }
        } else {
            minstack.push_back(x);
        }
    }
    
    void pop() {
        int e = stack[stack.size()-1];
        stack.pop_back();
        if (e == minstack[minstack.size()-1]) {
            minstack.pop_back();
        }
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return minstack[minstack.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
