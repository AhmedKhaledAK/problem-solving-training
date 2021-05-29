class Solution {
public:
    int minOperations(vector<int>& nums) {
        int len = (int) nums.size();
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] <= nums[i - 1]) {
                int val = nums[i - 1] - nums[i] + 1;
                nums[i] += val;
                ans += val;
            }
        }
        return ans;
    }
};
