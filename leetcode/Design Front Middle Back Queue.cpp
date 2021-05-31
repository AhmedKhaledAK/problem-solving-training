class FrontMiddleBackQueue {
private:
    deque<int> left;
    deque<int> right;
    
    void shiftLeft() {
        int item = right.front();
        right.pop_front();
        left.push_back(item);
    }
    
    void shiftRight() {
        int item = left.back();
        left.pop_back();
        right.push_front(item);
    }
    
    void balance() {
        if (left.size() > right.size()) {
            shiftRight();
        } 
        if (left.size() + 1 < right.size()) {
            shiftLeft();
        }
    }
    
public:
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        left.push_back(val);
        balance();
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        if (left.empty() && right.empty()) {
            return -1;
        }
        int item;
        if (left.empty()) {
            item = right.front();
            right.pop_front();
        } else {
            item = left.front();
            left.pop_front();
        }
        balance();
        return item;
    }
    
    int popMiddle() {
        if (right.empty()) {
            return -1;
        }
        int item;
        if (left.size() < right.size()) {
            item = right.front();
            right.pop_front();
        } else {
            item = left.back();
            left.pop_back();
        }
        balance();
        return item;
    }
    
    int popBack() {
        if (right.empty()) {
            return -1;
        }
        int item = right.back();
        right.pop_back();
        balance();
        return item;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */


/*

[10, 6, 5, 1, 11, 4, 3, 2, 7, 8, 9]
[6, 5, 1, 4, 3, 2]

*/