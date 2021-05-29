class NumArray {
private:
    int len;
    vector<int> blocks;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = (int) nums.size();
        len = (int) ceil(n/sqrt(n));
        blocks.resize(len);
        for (int i = 0; i < n; i++) {
            blocks[i / len] += nums[i];
        }
    }
    
    void update(int index, int val) {
        int idx = index / len;
        blocks[idx] = blocks[idx] - nums[index] + val;
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int startBlock = left / len;
        int endBlock = right / len;
        int sum = 0;
        if (startBlock == endBlock) {
            for (int i = left; i <= right; i++) {
                sum += nums[i];
            }
        } else {
            // first block
            for (int i = left; i <= (startBlock + 1) * len - 1; i++) {
                sum += nums[i];
            }
            // inbetween blocks
            for (int i = startBlock + 1; i <= endBlock - 1; i++) {
                sum += blocks[i];
            }
            // last block
            for (int i = endBlock * len; i <= right; i++) {
                sum += nums[i];
            }
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
