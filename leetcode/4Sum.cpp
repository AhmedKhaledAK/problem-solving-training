class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> > sets;
        if(nums.size() < 4) return sets; 
        
        sort(nums.begin(), nums.end());
        
        for(int i =0; i < nums.size()-3; i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            for(int j =i+1; j < nums.size(); j++){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;
                int s = j+1, e = nums.size()-1;
                while(s<e){
                    int ans = nums[i]+nums[j]+nums[s]+nums[e];
                    if(ans == target){
                        vector<int> v = {nums[i], nums[j], nums[s], nums[e]};
                        sets.push_back(v);
                        
                        while(s<e && nums[s] == v[2]) s++;
                        while(s<e && nums[e] == v[3]) e--;
                    } else if(ans < target) s++;
                    else e--;
                }
            }
        }
        return sets;
    }
};
