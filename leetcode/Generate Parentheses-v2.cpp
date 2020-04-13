class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strings;
        backtrack(strings, "", 0, 0, n);
        
        return strings;
    }
    
    void backtrack (vector<string> &strings, string s, int close, int open, int n) {
        if (s.length() == n*2) { 
            strings.push_back(s);
        }
        
        if (open < n) 
            backtrack(strings, s+'(', close, open+1, n);
        if (close < open) 
            backtrack(strings, s+')', close+1, open, n);
    }
};
