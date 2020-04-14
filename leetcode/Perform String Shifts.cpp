class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left = 0, right = 0;
        for (int i =0; i < shift.size(); i++) {
            if (shift[i][0] == 0) {
                left += shift[i][1];
            } else {
                right += shift[i][1];
            }
        }
        leftshift(s, left-right);
        rightshift(s, right-left);
        return s;
    }
    
    void leftshift (string &s, int n) {
        if (n<0) return; 
        int sz = s.length();
        n %= sz;
        string stemp = "";
        for (int i = 0; i < n; i++) {
            stemp += s[i];
        }
        s = s.substr(n, sz);
        for (int i = 0; i < stemp.length(); i++){
            s += stemp[i];
        }
    }
    
    void rightshift(string &s, int n) {
        if (n < 0) return;
        int sz = s.length();
        n %= sz;
        string stemp = "";
        for (int i = sz - n; i < sz; i++){
            stemp += s[i];
        }
        s = s.substr(0, sz - n);
        s.insert(0, stemp);
    }
};
