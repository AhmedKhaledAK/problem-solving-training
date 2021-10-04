class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int, pair<int,int>> firstLast;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (firstLast.find(s[i]) == firstLast.end()) {
                firstLast[s[i]] = {i, -1};
            } else {
                firstLast[s[i]].second = i;
            }
        }
        for (auto p : firstLast) {
            auto pa = p.second;
            if (pa.second != -1) {
                int left = pa.first, right = pa.second;
                unordered_set<int> uniques;
                for (int i = left + 1; i < right; i++) {
                    uniques.insert(s[i]);
                }
                ans += uniques.size();
            }
        }
        return ans;
    }
};
