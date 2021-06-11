class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(res, s, 0, curr);
        return res;
    }
    
    void dfs(vector<vector<string>> &res, string &s, int start, vector<string> &curr) {
        if (start >= s.length()) {
            res.push_back(curr);
        }
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(res, s, end + 1, curr);
                curr.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) {
                return false;
            }
        }
        return true;
    }
};




class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        vector<vector<string>> result;
        vector<string> current;
        dfs(result, s, 0, current, dp);
        return result;
    }
    
    void dfs(vector<vector<string>>& result, string &s, int start, vector<string> &current, 
            vector<vector<bool>> &dp) {
        // the whole string is a palindrome
        if (start >= s.length()) {
            result.push_back(current);
        }
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                current.push_back(s.substr(start, end - start + 1));
                dfs(result, s, end + 1, current, dp);
                current.pop_back();
            }
        }
    }
};