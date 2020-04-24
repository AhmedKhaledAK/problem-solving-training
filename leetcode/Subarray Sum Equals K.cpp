class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, pref = 0, n = nums.size();
        unordered_map<int, int> sums;
        sums[pref]++;
        for (int i =0; i < n; i++) {
            pref += nums[i];
            int diff = pref - k;
            ans += sums[diff];
            sums[pref]++;
        }
        return ans;
    }
};
