class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int sum = 0;
        
        for(int i =0; i < nums.size()-2; i++){
            int l = i+1, r = nums.size()-1;
            
            while(l < r){
                int ans = nums[i] + nums[l] + nums[r];
                int absolute = abs(target - ans);
                if(absolute == 0) return ans;
                if(absolute < closest){
                    closest = absolute;
                    sum = ans;
                }if(ans < target)
                    l++;
                else 
                    r--;
            }
        }
        return sum;
    }
};
