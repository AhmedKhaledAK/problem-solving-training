class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = (int) nums.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int>::iterator lower;
        lower = lower_bound(nums.begin(), nums.end(), target);
        
        if (lower != nums.end()) {
            return lower - nums.begin();
        }
        // a check to avoid looping on special cases
        if (target > nums[n - 1]) {
            return n;
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < target && nums[i + 1] > target) {
                return i + 1;
            }
        }
        return 0;
    }
};
