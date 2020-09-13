class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.length(), nt = t.length();
        if (abs(ns - nt) > 1 || s == t) {
            return false;
        }
        int i, j, cnt;
        i = j = cnt = 0;
        while (i < ns && j < nt) {
            if (s[i] == t[j]) {
                i++;
                j++;
                continue;
            }
            if (s[i] != t[j] && ns > nt) {  // a character to be deleted
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                i++;
                continue;
            }
            if (s[i] != t[j] && ns < nt) {  // a character to be added
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                j++;
                continue;
            }
            if (s[i] != t[j]) { // a character to be replaced
                cnt++;
                if (cnt > 1) {
                    return false;
                }
                i++;
                j++;
            }
        }
        return cnt == 1 || (cnt == 0 && (i < ns || j < nt));
    }
};
