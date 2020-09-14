class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                int j = n - 1 - i;
                return (isPalindromeRange(s, i + 1, j)) || isPalindromeRange(s, i, j - 1);
            }
        }
        return true;
    }
    
    bool isPalindromeRange(string s, int start, int end) {
        for (int i = start; i <= start + (end - start) / 2; i++) {
            if (s[i] != s[end - i + start]) {
                return false;
            }
        }
        return true;
    }
};
