class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (start != 0) {
                    s[start++] = ' ';
                }
                int end = i;
                while (end < s.size() && s[end] != ' ') 
                    s[start++] = s[end++];
                reverse(s.begin() + start - (end - i), s.begin() + start);
                i = end;
            }
        }
    }
};
