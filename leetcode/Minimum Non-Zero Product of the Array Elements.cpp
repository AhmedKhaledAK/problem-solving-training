class Solution {
public:
    int minNonZeroProduct(int p) {
        long long range = pow(2, p);
        range--;
        long long mod = pow(10, 9) + 7;
        long long ans = myPow(range - 1, range / 2, mod);
        return (ans * (range % mod)) % mod;
    }
    
    long long myPow(long long base, long long exp, long long mod) {
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        long long ans = myPow(base, exp / 2, mod);
        if (exp  % 2 == 0) {
            return (ans * ans) % mod;
        } 
        ans = ans * ans % mod;
        base %= mod;
        return (ans * base) % mod;
    }
};
