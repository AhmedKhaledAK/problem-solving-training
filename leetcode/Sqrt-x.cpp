class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        
        int low = 1, high = x, ans;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;
            if (val == x) {
                return mid;
            }
            if (val < x) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
