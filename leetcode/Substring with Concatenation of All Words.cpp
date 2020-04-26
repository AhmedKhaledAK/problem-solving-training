class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0) {
            return ans;
        }
        
        int word_size = words[0].size();
        int words_cnt = (int) words.size();
        int total_size = word_size * words_cnt;
        
        if (s.length() < total_size) {
            return ans;
        }
        
        unordered_map<string, int> occ;
        
        for (string str : words) {
            occ[str]++;
        }
        
        for (int i = 0; i <= s.length() - total_size; i++) {
            unordered_map<string, int> temp_occ(occ);
            
            int j = i, cnt = words_cnt;
            while (j < i + total_size) {
                string sub = s.substr(j, word_size);
                
                if (occ.find(sub) == occ.end() || temp_occ[sub] == 0) {
                    break;
                }
                temp_occ[sub]--;
                cnt--;
                j+=word_size;
            }
            if (cnt == 0) ans.push_back(i);
        }
        
        return ans;
    }
};
