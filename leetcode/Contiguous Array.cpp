class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) nums[i] = -1;
        }
        
        vector<int> prefsum;
        prefsum.push_back(0);
        
        for (int i = 0; i < n; i++) 
            prefsum.push_back(nums[i] + prefsum.back());
        unordered_map<int, int> mp; // first occurrence                 
        
        for (int i =0; i < n+1; i++) {
            if (mp.find(prefsum[i]) != mp.end()) {
                ans = max(ans, i - mp[prefsum[i]]);
            } else {
                mp[prefsum[i]] = i;
            }
        }
            
        return ans;
    }
};
