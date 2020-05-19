class StockSpanner {
    
private:
    vector<int> nums;
    pair<int, int> mxp;
    pair<int, int> mnp;
    
    int getDays (int back, int front, int price) {
        int cnt = 0;
        for (int i = back; i >= front; i--) {
            if (nums[i] > price) {
                break;
            }
            cnt++;
        }
        return cnt;
    }
    
public:
    StockSpanner() {
        mxp.first = INT_MIN;
        mxp.second = -1;
        mnp.first = INT_MAX;
        mnp.second = -1;
    }
    
    int next(int price) {
        nums.push_back(price);
        if (nums.size() == 1) {
            mxp.first = mnp.first = price;
            mxp.second = mnp.second = 0;
            return 1;
        }
        if (price >= mxp.first) {
            mxp.second = nums.size() - 1;
            mxp.first = price;
            return nums.size();
        }
        int st, end;
        st = nums.size() - 1;
        if (price < mnp.first) {
            mnp.first = price;
            end = mnp.second;
            mnp.second = nums.size() - 1;
        } else if (price < mxp.first) {
            end = mxp.second;
        }
        return getDays(st, end, price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
