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



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            sum = nums[i] + max(0, sum);
            ans = max(sum, ans);
        }
        return ans;
    }
};