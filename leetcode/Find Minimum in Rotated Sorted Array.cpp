class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 1) {
            return nums[0];
        }
        
        int left = 0, right = n - 1;
        
        if (nums[right] > nums[left]) { // no rotation
            return nums[0];
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]){
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

/*

[3,4,5,6,7,1,2] 


[2,3,4,5,6,7,1]

*/
