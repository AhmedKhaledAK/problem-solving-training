class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (string word : words) {
            if (match(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
    
    bool match(string word, string pattern) {
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c1 = word[i];
            char c2 = pattern[i];
            if (m1.find(c1) == m1.end()) {
                m1[c1] = c2;
            }
            if (m2.find(c2) == m2.end()) {
                m2[c2] = c1;
            }
            if (m1[c1] != c2 || m2[c2] != c1) {
                return false;
            }
        }
        return true;
    } 
};
