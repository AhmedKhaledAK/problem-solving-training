class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            if (nums[0] == 1) return 2;
            return 1;
        }
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                idx++;
                swap(nums[i], nums[idx]);
            }
        }
        n = idx;
        for (int i = 0; i <= n; i++) {
            if (abs(nums[i]) - 1 <= n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
            
        for (int i = 0; i <= n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 2;
    }
};
