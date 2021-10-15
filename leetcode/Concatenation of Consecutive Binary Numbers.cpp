class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            long long bitsNum = (log(i) / log(2)) + 1;
            ans = ans << bitsNum;
            ans |= i;
            ans %= 1000000007;
        }
        return ans;
    }
};
