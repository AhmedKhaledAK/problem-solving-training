class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int idx = -1, len = n;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                idx++;
                swap(nums[i], nums[idx]);
            } else len--;
        }
        return len;
    }
};
