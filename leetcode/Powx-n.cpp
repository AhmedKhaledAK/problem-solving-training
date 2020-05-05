class Solution {
public:
    double myPow(double x, int n) {
        double ans = pow2(x, n);
        return n < 0 ? (1 / ans) : ans;
    }
    double pow2(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double ans = pow2(x, n / 2);
        if (n % 2 == 0) {
            return ans * ans;
        }
        return x * ans * ans;
    }
};
