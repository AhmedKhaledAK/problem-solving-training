class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int s = 0, e = n-1, first = nums[0];
        
        int target_big = target >= first;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int value = nums[mid];
            if (value == target) {
                return mid;
            }
            int am_big = value >= first;
            
            if (am_big == target_big) {
                if (value < target) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            } else {
                if (am_big) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
};
