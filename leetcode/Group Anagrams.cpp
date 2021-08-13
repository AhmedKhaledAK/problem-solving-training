class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string s : strs) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            anagrams[s1].push_back(s);
        }
        vector<vector<string>> res;
        for (auto it = anagrams.begin(); it != anagrams.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};