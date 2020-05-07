class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length(), nb = b.length();
        string ans = "";
        
        // min string in length
        string mins = na <= nb ? a : b;
        // max string in length
        string maxs = na <= nb ? b : a;
        
        int i = mins.length() - 1, j = maxs.length() - 1, rem = 0; 
        while (j >= 0) {
            int plus;
            if (i >= 0) {
                plus = mins[i] - '0' + maxs[j] - '0' + rem;
            } else {
                plus = maxs[j] - '0' + rem;
            }
            ans += to_string(plus % 2);
            rem = plus / 2;
            i--;
            j--;
        }
        
        ans += to_string(rem);
        
        while (ans.length() != 1 && *prev(ans.end()) == '0') {
            ans.erase(prev(ans.end()));
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
