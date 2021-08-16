class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(helper(nums, firstLen, secondLen), helper(nums, secondLen, firstLen));
    }
    
    int helper(vector<int>& nums, int x, int y)
    {
        int n = (int) nums.size();
        vector<int> left(n, 0), right(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < x)
            {
                sum += nums[i];
                left[i] = sum;
            }
            else
            {
                sum = sum + nums[i] - nums[i - x];
                left[i] = max(sum, left[i - 1]);
            }
        }
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + y > n - 1)
            {
                sum += nums[i];
                right[i] = sum;
            }
            else
            {
                sum = sum + nums[i] - nums[i + y];
                right[i] = max(sum, right[i + 1]);
            }
        }
        int ans = 0;
        for (int i = x - 1; i < n - y; i++)
        {
            ans = max(ans, left[i] + right[i + 1]);
        }
        return ans;
    }
};
