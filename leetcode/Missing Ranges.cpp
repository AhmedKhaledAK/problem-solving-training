class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = (int) nums.size();
        
        vector<string> res;
        
        if (n == 0) {
            return{helper(lower,upper)};
        }
        
        if (nums[0] > lower) {
            res.push_back(helper(lower,nums[0]-1)); 
        } 
        for (int i=1; i<nums.size(); i++) {
            if(nums[i-1] == INT_MAX) return res; 
            
            if (nums[i]  == nums[i-1] + 1 || nums[i] == nums[i-1]) continue; // to handle int_max
            else {
              res.push_back(helper(nums[i-1]+1, nums[i]-1)); 
            }
               
        }
         if (upper > nums[nums.size()-1])
           res.push_back(helper(nums[nums.size()-1]+1 ,upper)); 
              
        return res; 
    }
    
    string helper(int lower , int upper){
        
        string str; 
        
        str += to_string(lower); 
        if (upper != lower) {
            str += "->";             
            str += to_string(upper);            
        }        
        return str ;          
    }
};
