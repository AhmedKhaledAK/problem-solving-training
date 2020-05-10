class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.length(), nt = t.length();
        unordered_map<int, int> occ, curr;
        int len = 0;
        for (char c : t) {
            occ[c]++;
            if (occ[c] == 1) {
                len++;  // counts the length of the unique elements
            }
        }
        
        int j = 0, low = 1, high = INT_MAX, curr_cnt = 0;
        for (int i = 0; i < ns; i++) {
            curr[s[i]]++;
            if (curr[s[i]] == occ[s[i]]) {
                curr_cnt++;
            }
            while (j < i && curr_cnt == len && curr[s[j]] > occ[s[j]]) {
                curr[s[j]]--;
                j++;
            }
            if (curr_cnt == len) {
                if (i - j + 1 < high - low + 1) {
                    low = j;
                    high = i;
                }
            }
        }
        if (high == INT_MAX) {
            return "";
        }
        return s.substr(low, high - low + 1);
    }
};
