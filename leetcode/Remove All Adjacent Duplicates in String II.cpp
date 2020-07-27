class Solution {
public:
    string removeDuplicates(string S, int k) {
        stack<int> st;
        for (int i = 0; i < S.size(); i++)  {
            if (i == 0 || S[i] != S[i - 1]) {
                st.push(1);
            } else {
                if (++st.top() == k) {
                    st.pop();
                    S.erase(i - k + 1, k);
                    i -= k;
                }
            }
        }
        return S;
    }
};
