class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod;
        prod.push_back(1);
        for (int i = 1; i < nums.size(); i++) {
            prod.push_back(nums[i-1]*prod[i-1]);
        }
        int p = 1;
        for (int i = nums.size()-2; i >= 0; i--) {
            prod[i] *= nums[i+1]*p;
            p*=nums[i+1];
        }
        return prod;
    }
};
