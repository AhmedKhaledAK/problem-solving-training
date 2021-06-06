class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int total_sum, array_sum;
        total_sum = array_sum = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            array_sum += nums[i];
            total_sum += i + 1;
        }
        return total_sum - array_sum;
    }
};