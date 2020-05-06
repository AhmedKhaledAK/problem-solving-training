class Solution {
public:
    bool isNumber(string s) {
        int n  = s.length(); 
        if (n == 0) {
            return false;
        }
        
        int st = 0, e = n - 1;
        while (st < n && s[st] == ' ') {
            st++;
        }
        if (st == n) {
            return false;
        }
        while (e >= 0 && s[e] == ' ') {
            e--;
        }
        
        bool sign = false, point = false, exp = false; 
        for (int i = st; i <= e; i++) {
            if (i == st && (s[i] == '+' || s[i] == '-')) {
                sign = true;
                continue;
            }
            if (i != st && !exp && (s[i] == '+' || s[i] == '-')) {
                return false;
            }
            if (i != st && (s[i] == '+' || s[i] == '-') && s[i - 1] != 'e') {
                return false;
            }
            if (s[i] == 'e') {
                if (exp || i == st || i == e || (i > st && !isdigit(s[i - 1]) 
                                                 && ( (i - 2 >= st && !isdigit(s[i - 2]) ) 
                                                     || i - 2 < st ) )) {
                    return false;
                }
                exp = true;
                continue;
            }
            if (s[i] == '.') {
                if (exp || point || st == e || (i > st && !isdigit(s[i - 1]) && i == e)) {
                    return false;
                }
                point = true;
                continue;
            }
            if (!isdigit(s[i]) && ( (s[i] != 'e' && s[i] != '-' && s[i] != '+') || i == e) ) {
                return false;
            }
        }
        return true;
    }
};
