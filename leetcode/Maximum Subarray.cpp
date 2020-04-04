class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            dp[i] = nums[i] + max(0, dp[i-1]);
        }
        
        return *max_element(dp, dp+nums.size());
    }
};
