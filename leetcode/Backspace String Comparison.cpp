class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int delS = 0, delT = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') { 
                    delS++;
                    i--;
                } else if (delS > 0) {
                    delS--;
                    i--;
                } else break;
            }
            
            while (j >= 0) {
                if (T[j] == '#') {
                    delT++;
                    j--;
                } else if (delT > 0) {
                    delT--;
                    j--;
                } else break;
            }
            
            if (i >= 0 && j>= 0 && S[i] != T[j]) 
                return false;
            
            if ((i >= 0) != (j >= 0))
                return false;
            
            i--;
            j--;
        }
        return true;
    }
};
