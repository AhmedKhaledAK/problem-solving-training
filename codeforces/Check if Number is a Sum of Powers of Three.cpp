class Solution {
public:
    bool checkPowersOfThree(int n) {
        int k = log2(n) / log2(3);
        k = pow(3,k);
        if (n - k == 0) {
            return true;
        } else if (n - k < k) {
            return checkPowersOfThree(n - k);
        } else {
            return false;
        }
    }
};
