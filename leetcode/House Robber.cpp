class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax, currMax;
        prevMax = currMax = 0;
        for (int n : nums) {
            int temp = currMax;
            currMax = max(currMax, prevMax + n);
            prevMax = temp;
        }
        return currMax;
    }
};
