class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i] - k)) {
                ans += mp[nums[i] - k];
            }
            if (mp.count(nums[i] + k)) {
                ans += mp[nums[i] + k];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};
