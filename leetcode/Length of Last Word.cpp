class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int j = s.length() - 1;
        while (j >= 0 && s[j] == ' ') {
            j--;
        }
        for (int i = j; i >= 0; i--) {
            if (s[i] == ' ') {
                len += j - i;
                break;
            } else if (i == 0) {
                len += j + 1 - i;
                break;
            }
        }
        return len;
    }
};
