#include <bits/stdc++.h> 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > sets;
        
        if(nums.size() < 3) return sets;
        
        sort(nums.begin(), nums.end());
        
        
        for(int i =0; i < nums.size()-2; i++){
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i+1, r = nums.size()-1;
            
            while(l < r){
                int ans = nums[i] + nums[l] + nums[r];
                if(ans == 0){
                    vector<int> set = {nums[i], nums[l], nums[r]};
                    sets.push_back(set);
                    
                    while(l < r && nums[l] == set[1])
                        l++;
                    
                    while(l < r && nums[r] == set[2])
                        r--;
                    
                } else if(ans < 0){
                    l++;
                } else {
                    r--;
                }
            }
        }
        return sets;
    }
};
