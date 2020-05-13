class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        int len = s1.length();
        vector<char> freq(26);
        for (int i = 0; i < len; i++) {
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                return false;
            }
        }
        
        for (int i = 1; i < len; i++) {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) {
                return true;
            }
            s21 = s2.substr(0, len - i);
            s22 = s2.substr(len - i, len);
            if (isScramble(s11, s22) && isScramble(s12, s21)) {
                return true;
            }
        }
        return false;
    }
};
