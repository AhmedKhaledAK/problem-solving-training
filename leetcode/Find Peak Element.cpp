class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = (int) nums.size();
        
        int l = 0, h = n - 1;
        
        while (l < h) {
            int mid = (l + h) / 2;
            if (nums[mid] > nums[mid + 1]) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
        
    }
};
