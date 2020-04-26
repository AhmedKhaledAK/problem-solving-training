class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = (int) nums.size() - 1;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= last) {
                last = i;
            }
        }
        return last == 0;
    }
};
