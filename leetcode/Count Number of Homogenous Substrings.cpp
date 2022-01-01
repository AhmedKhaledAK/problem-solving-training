class Solution {
public:
    int countHomogenous(string s) {
        int prev = s[0];
        long k = 1;
        int mod = 1000000007;
        long ans = 0;
        int n = (int) s.size();
        for (int i = 1; i < n; i++) {
            if (prev == s[i]) {
                k++;
            } else {
                ans = (ans + k * (k + 1) / 2) % mod;
                k = 1;
                prev = s[i];
            }
        }
        ans = (ans + k * (k + 1) / 2) % mod;
        return ans;
    }
};
