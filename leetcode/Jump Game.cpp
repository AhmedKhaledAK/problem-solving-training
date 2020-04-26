class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp; // memoization
        dp.assign((int) nums.size(), -1);
        return canJump(nums, 0, dp);
    }
    bool canJump(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= (int) nums.size() - 1) {
            return true;
        }
        int max_jumps = nums[i];
        for (int j = 1; j <= max_jumps; j++) {
            if (i + j < (int) nums.size() && dp[i + j] != -1) {
                continue;
            }
            bool val = canJump(nums, i + j, dp);
            dp[i + j] = val;
            if (val == true) {
                return true;
            }
        }
        return false;
    }
};
