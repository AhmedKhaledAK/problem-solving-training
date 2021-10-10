class Solution {
public:
    bool hasAlternatingBits(int n) {
        int curr = n & 1;
        n >>= 1;
        while (n > 0) {
            if (curr == (n & 1)) {
                return false;
            }
            curr = n & 1;
            n >>= 1;
        }
        return true;
    }
};
