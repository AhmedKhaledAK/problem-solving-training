class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, n = s.length() - 1;
        for (char c : s) {
            if (c == '(' || c == '*') {
                balance++;
            } else if (--balance == -1) {
                return false;
            }
        }
        balance = 0;
        for (int i = n; i >= 0; i--) {
            if (s[i] == ')' || s[i] == '*') {
                balance++;
            } else if (--balance == -1) {
                return false;
            }
        }
        return true;
    }
};
