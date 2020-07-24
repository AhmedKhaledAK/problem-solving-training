class Solution {
    
    static bool cmp(pair<string, int>& x, pair<string, int>& y) {
        if (x.second < y.second) { 
            return false; 
        } else if (x.second > y.second) { 
            return true; 
        } else { 
            if (x.first < y.first) { 
                return true; 
            } else { 
                return false; 
            } 
        } 
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        if (words.size() == 0) {
            return {};
        }
        unordered_map<string, int> mp;
        for (string word : words) {
            mp[word]++;
        }
        vector<pair<string, int>> vp;
        vector<string> ans;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vp.push_back({it->first, it->second});
        }
        sort(vp.begin(), vp.end(), cmp);
        
        for (int i = 0; i < k; i++) {
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};
