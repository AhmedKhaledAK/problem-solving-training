class CustomStack {
private:
    vector<int> custom_stack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (custom_stack.size() < maxSize) {
            custom_stack.push_back(x);
        }
    }
    
    int pop() {
        if (custom_stack.empty()) {
            return -1;
        } 
        int val = custom_stack[custom_stack.size() - 1];
        custom_stack.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        if (!custom_stack.empty()){
            for (int i = 0; i < k && i < custom_stack.size(); i++) {
                custom_stack[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
