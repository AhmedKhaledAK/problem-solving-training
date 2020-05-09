class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1, e = num; 
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long val = mid * mid;
            if (val == num) {
                return true;
            } 
            if (val < num) {
                s = mid + 1;
            } else if (val > num) {
                e = mid - 1;
            }
        }
        return false;
    }
};
