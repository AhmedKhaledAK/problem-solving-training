class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = 0, length = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } 
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
            length = max(length, dp[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (length == dp[i])
            {
                ans += count[i];
            }
        }
        return ans;
    }
};
