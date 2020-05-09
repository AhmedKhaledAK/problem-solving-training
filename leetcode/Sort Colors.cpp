class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int) nums.size();
        int idx = -1;
        
        
        for (int j = 2; j > 0; j--) {
            idx = -1;
            for (int i = 0; i < n; i++) {
                if (nums[i] != j) {
                    idx++;
                    swap(nums[i], nums[idx]);
                }
            }
            n = idx + 1;
        }
    }
};
