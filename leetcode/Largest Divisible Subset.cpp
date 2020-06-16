class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> ans;
        if (n == 0) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        vector<int> dp(n + 1, 1);
        int mx = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = dp[j] + 1;
                    mx = max(mx, dp[i]);
                }
            }
        }
        
        int prev = -1;
        for (int i = n-1; i >= 0; i--) {
            if (dp[i] == mx && (prev == -1 || prev % nums[i] == 0)) {
                mx--;
                prev = nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
