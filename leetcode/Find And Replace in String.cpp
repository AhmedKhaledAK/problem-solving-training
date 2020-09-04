class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = S.length();
        vector<int> match(n);
        fill(match.begin(), match.end(), -1);
        
        string ans = "";
        
        for (int i = 0; i < indexes.size(); i++) {
            int ix = indexes[i];
            if (S.substr(ix, sources[i].length()) == sources[i]) {
                match[ix] = i;
            }
        }
        
        int ix = 0;
        
        while (ix < n) {
            if (match[ix] >= 0) {
                ans.append(targets[match[ix]]);
                ix += sources[match[ix]].length();
            } else {
                ans += S[ix++];
            }
        }
        
        return ans;
    }
};
