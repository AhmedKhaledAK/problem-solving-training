class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> st;
        stack<int> ks;
        int i = 0;
        while (i < s.length()){
            if (s[i] >= 48 && s[i] <= 57) {
                int k = 0;
                while (s[i] >= 48 && s[i] <= 57) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                ks.push(k);
            } else if (s[i] == '[') {
                st.push(ans);
                ans = "";
                i++;
            } else if (s[i] == ']') {
                string temp = st.top();
                st.pop();
                int k = ks.top();
                ks.pop();
                for (int j = 0; j < k; j++) {
                    temp += ans;
                }
                ans = temp;
                i++;
            } else {
                ans += s[i++];
            }
        }
        return ans;
    }
};
