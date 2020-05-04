class Solution {
public:
    int jump(vector<int>& nums) {
        int n = (int) nums.size();
        int curr_furthest = 0, curr_end = 0, jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            curr_furthest = max(curr_furthest, nums[i] + i);
            if (i == curr_end) {
                jumps++;
                curr_end = curr_furthest;
            }
        }
        return jumps;
    }
};
