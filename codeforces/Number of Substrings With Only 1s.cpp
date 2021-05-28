class Solution {
public:
    int numSub(string s) {
        int MOD = 1000000007;
        long long int cnt, sum;
        cnt = sum = 0;
        for (int i = 0; i < s.length(); i++) {
            cnt = 0;
            while (i < s.length() && s[i] == '1') {
                cnt++;
                i++;
            }
            sum = (sum + (cnt * (cnt + 1) / 2)%MOD)%MOD;
        }
        return sum;
    }
};
