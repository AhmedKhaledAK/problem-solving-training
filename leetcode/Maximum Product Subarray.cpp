class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) return 0;
        
        int max_so_far, min_so_far, res;
        max_so_far = min_so_far = nums[0];
        res = max_so_far;
        
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int temp = max({curr, max_so_far * curr, min_so_far * curr});
            min_so_far = min({curr, max_so_far * curr, min_so_far * curr});
            
            max_so_far = temp;
            
            res = max(res, max_so_far);
        }
        return res;
    }
};
