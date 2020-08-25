class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        
        vector<int> charLefts;
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i - 1] != s[i]) {
                charLefts.push_back(i);
            }
        }
        charLefts.push_back(s.length());
        unordered_set<char> chars;
        int ans = 0, weight = 0;
        for (int i = 0; i < (int) charLefts.size() - 1; i++) {
            chars.insert(s[charLefts[i]]);
            weight += charLefts[i + 1] - charLefts[i];
            
            if (chars.size() >= 3) {
                weight = 0;
                chars.clear();
                i = i - 2;
                continue;
            }
            ans = max(ans, weight);
        }
        return ans;
    }
};
