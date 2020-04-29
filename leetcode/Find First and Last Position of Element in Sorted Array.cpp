class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        if (upper == 0 || nums[upper - 1] != target) {
            lower = -1;
            upper = 0;
        }
        
        ans.push_back(lower);
        ans.push_back(upper - 1);
        return ans;
    }
};
