class Solution {
    
    unordered_map<string, int> dp;
    
public:
    int minCut(string s) {
        if (dp.count(s) != 0) {
            return dp[s];
        }
        if (s.length() <= 1 || isPalindrome(s)) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = 1; i < s.length(); i++) {
            if (isPalindrome(s.substr(0, i))) {
                ans = min(ans, 1 + minCut(s.substr(i)));
            }
        }
        return dp[s] = ans;
    }
    
    
    bool isPalindrome(string s) {
        int low = 0, high = s.length() - 1;
        while (low < high) {
            if (s[low++] != s[high--]) {
                return false;
            }
        }
        return true;
    }
};
