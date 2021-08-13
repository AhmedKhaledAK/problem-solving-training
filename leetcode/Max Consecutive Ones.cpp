class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                ans = max(ans, count);
                count = 0;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};