class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int) nums.size();
        int i = n - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            i--;
        }
        if (i <= 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        int e = nums[i];
        int low = i + 1, high = n - 1, idx = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = nums[mid];
            if (val <= e) {
                high = mid - 1;
            } else {
                low = mid + 1;
                if (idx == -1 || nums[idx] >= val) {
                    idx = mid;
                }
            }
        }
        swap(nums[i], nums[idx]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};
