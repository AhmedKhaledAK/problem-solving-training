class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        } 
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ans[i] = 0;
            } else if (s[i] == ')' && i > 0) {
                if (s[i - 1] == '(') {
                    if (i - 2 >= 0) {
                        ans[i] = ans[i - 2] + 2;
                    } else {
                        ans[i] = ans[i - 1] + 2;
                    }
                } else {
                    if (i - ans[i - 1] - 1 >= 0 && s[i - ans[i - 1] - 1] == '(') {
                        if (i - ans[i - 1] - 2 >= 0) {
                            ans[i] = ans[i - 1] + 2 + ans[i - ans[i - 1] - 2];
                        } else {
                            ans[i] = ans[i - 1] + 2;
                        }
                    } else {
                        ans[i] = 0;
                    }
                }
            } else {
                ans[i] = 0;
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};
