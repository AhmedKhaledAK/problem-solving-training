class Solution {
public:
    string frequencySort(string s) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        vector<pair<int, char>> vpr;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            vpr.push_back({it->second, it->first});
        }
        sort(vpr.begin(), vpr.end());
        reverse(vpr.begin(), vpr.end());
        string ans = "";
        for (pair<int, char> pr : vpr) {
            for (int i = 0; i < pr.first; i++) {
                ans.push_back(pr.second);
            }
        }
        return ans;
    }
};
