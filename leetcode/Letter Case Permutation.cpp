class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        rec(s, 0, ans);
        return ans;
    }
    
    void rec(string s, int i, vector<string>& ans) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }
        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
            rec(s, i + 1, ans);
            s[i] = toupper(s[i]);
            rec(s, i + 1, ans);
        } else {
            rec(s, i + 1, ans);
        }
    }
};
