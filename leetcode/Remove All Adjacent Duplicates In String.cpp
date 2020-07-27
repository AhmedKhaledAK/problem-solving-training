class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        st.push(S[0]);
        string ans = "";
        for (int i = 1; i < S.length(); i++) {
            if (!st.empty()) {
                char c = st.top();
                if (S[i] != c) {
                    st.push(S[i]);
                } else {
                    while (c == S[i] && !st.empty()) {
                        st.pop();
                        if (st.empty()) break;
                        c = st.top();
                    }
                }
            } else {
                st.push(S[i]);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
