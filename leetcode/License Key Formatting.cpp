class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int n = S.length();
        int sz = 0;
        for (int i = 0; i < n; i++) {
            if (S[i] != '-') sz++; 
        }
        if (sz == 0) {
            return "";
        }
        int grps = sz / K;
        string ans = "";
        int x = n - 1;
        for (int i = 0; i < grps; i++) {
            string grp = "";
            int j = 0;
            while (j != K) {
                if (S[x] != '-') {
                    j++;
                    grp += toupper(S[x]);
                }
                x--;
            }
            ans += grp;
            ans += '-';
        }
        while (x >= 0) {
            if (S[x] != '-') ans += toupper(S[x]);
            x--;
        }
        if (ans[ans.length() - 1] == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
