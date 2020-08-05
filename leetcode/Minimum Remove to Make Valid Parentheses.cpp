class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<pair<char,int>> stp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && stp.empty()) {
                s[i] = '.'; // mark as deleted
            } else if (s[i] == ')') {
                stp.pop();
            } else if (s[i] == '(') {
                stp.push({s[i], i});
            }
        }
        while (!stp.empty()) {
            s[stp.top().second] = '.';
            stp.pop();
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '.') {
                ans += s[i];
            }
        }
        return ans;
    }
};
