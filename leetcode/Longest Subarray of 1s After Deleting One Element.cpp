class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sz = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        if (mx == 1 && mn == 1)
        {
            return sz - 1;
        }
        else if (mx == 0 && mn == 0)
        {
            return 0;
        }
        vector<int> left(sz, 0), right(sz, 0);
        left[0] = nums[0] == 1;
        for (int i = 1; i < sz; i++)
        {
            if (nums[i] == 1)
            {
                left[i] = 1 + left[i - 1];
            }
        }
        right[sz - 1] = nums[sz - 1] == 1;
        for (int i = sz - 2; i >= 0; i--)
        {
            if (nums[i] == 1)
            {
                right[i] = 1 + right[i + 1];
            }
        }
        int ans = 0;
        for (int i = 1; i < sz - 1; i++)
        {
            if (left[i] == 0)
            {
                ans = max(left[i - 1] + right[i + 1] , ans);
            }
        }
        return ans;
    }
};
