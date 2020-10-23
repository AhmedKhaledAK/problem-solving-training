class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return nums[0];
        }
        
        return max(houseRobber(nums, 0, n - 2), houseRobber(nums, 1, n - 1));
    }
    
    int houseRobber(const vector<int> & nums, int s, int e) {
        int currMax, prevMax;
        currMax = prevMax = 0;
        for (int i = s; i <= e; i++) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        return currMax;
    }
};
