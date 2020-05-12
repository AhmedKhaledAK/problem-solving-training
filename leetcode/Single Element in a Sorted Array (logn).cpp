class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) {
            return nums[0];
        }
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ( (mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]) ) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return nums[low];
    }
}; 
// time: O(logn), space: O(1)
