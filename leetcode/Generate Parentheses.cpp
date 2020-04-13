class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> strings;
        if (n == 0) return strings;
        unordered_map<string, bool> mp;
        backtrack(strings, '(', "", n, mp);
        
        for (auto s : strings)
            cout << s << endl;
        
        return strings;
    }
    
    void backtrack (vector<string> &strings, char bracket, string s, int n, 
                    unordered_map<string, bool> &mp) {
        if (s.length() < n*2) {
            s+=bracket;
            backtrack(strings, '(', s, n, mp);
            backtrack(strings, ')', s, n, mp);
        } else if (s.length() == n*2 && !mp[s] && isvalid(s)) {
            strings.push_back(s);
            mp[s] = true;
        }
        s.pop_back();
    }
    
    bool isvalid (string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(') cnt++;
            else cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
    
};
