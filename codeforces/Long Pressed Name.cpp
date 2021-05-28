class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length()) return false;
        int i, j;
        i = j = 0;
        int n = name.length();
        int t = typed.length();
        
        while (i < n && j < t) {
            if (name[i] != typed[j]) {
                return false;
            }
            char c = name[i];
            int cntN, cntT;
            cntN = cntT = 0;
            while (i < n && name[i] == c) {
                cntN++;
                i++;
            }
            while (j < t && typed[j] == c) {
                cntT++;
                j++;
            }
            if (cntN > cntT) {
                return false;
            }
        }
        if (i == n && j == t) {
            return true;
        }
        return false;
    }
};
