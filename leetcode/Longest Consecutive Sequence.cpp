class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ((int) nums.size() == 0) {
            return 0;
        }
        int n = (int) nums.size(), ans = 0;
        unordered_set<int> S(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (S.find(nums[i] - 1) == S.end()) {
                int el = nums[i];
                while (S.find(el) != S.end()) {
                    el++;
                }
                ans = max(ans, el - nums[i]);
            }
        }
        return ans;
    }
};
