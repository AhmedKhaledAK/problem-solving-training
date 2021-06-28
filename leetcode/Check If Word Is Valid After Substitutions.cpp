class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a' || s[i] == 'b') {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != 'b') return false;
                st.pop();
                if (st.empty() || st.top() != 'a') return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};