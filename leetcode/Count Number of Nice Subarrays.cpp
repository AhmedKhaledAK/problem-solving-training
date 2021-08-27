class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int ans, odd;
        ans = odd = 0;
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefix[odd]++;
            if (nums[i] % 2 != 0)
            {
                odd++;
            }
            if (odd >= k)
            {
                ans += prefix[odd - k];
            }
        }
        return ans;
    }
};
