class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = (int) nums.size();
        if (n == 0) {
            return false;
        }
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int value = nums[mid];
            
            if (value == target) {
                return true;
            }
            
            if (nums[low] < value) {
                if (target >= nums[low] && value > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[low] == value) {
                low++;
            } else {    // nums[low] > value
                if (target > value && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
