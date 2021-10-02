class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = (int) arr.size();
        if (n == 0) return 0;
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i : arr) {
            mp[i] = 1 + mp[i - difference];
            ans = max(ans, mp[i]);
        }
        return ans;
    }
};
