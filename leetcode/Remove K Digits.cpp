class Solution {
public:
    string removeKdigits(string num, int k) {
        string minstring = "";
        solve(num, k, minstring);
        while (minstring.size() > 0 && minstring.size() != 1 && minstring[0] == '0') {
            minstring = minstring.substr(1, minstring.length());
        } 
        if (minstring == "") {
            minstring = "0";
        }
        return minstring;
    }
    
    void solve (string num, int k, string& minstring) {
        if (k == 0) {
            minstring.append(num);
            return;
        }
        int len = num.length();
        if (len <= k) {
            return; // empty string
        }
        int mnidx = 0;
        for (int i = 1; i <= k; i++) {
            if (num[i] < num[mnidx]) {
                mnidx = i;
            }
        }
        minstring.push_back(num[mnidx]);
        string substring = num.substr(mnidx + 1, len - mnidx);
        solve(substring, k - mnidx, minstring);
    }
};
