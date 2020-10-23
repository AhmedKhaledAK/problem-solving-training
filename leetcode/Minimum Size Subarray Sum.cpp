class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = (int) nums.size();
        int j, i, sum, ans;
        i = j = sum = 0;
        ans = INT_MAX;
        while (i < n) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
            i++;
        }
        return ans != INT_MAX ? ans : 0;
    }
};
