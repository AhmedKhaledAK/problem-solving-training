struct RLE {
    string key;
    vector<int> counts;
    
    RLE(string S) {
        string k = "";
        int prev = -1;
        for (int i = 0; i < S.length(); i++) {
            if (i == S.length() - 1 || S[i] != S[i + 1]) {
                k += S[i];
                counts.push_back(i - prev);
                prev = i;
            }
        }
        key = k;
    }
};


class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        RLE R(S);
        int ans = 0;
        int flag = 0;
        for (string word : words) {
            flag = 0;
            RLE R2(word);
            if (R.key != R2.key) {
                continue;
            }
            for (int i = 0; i < R.counts.size(); i++) {
                int c1 = R.counts[i];
                int c2 = R2.counts[i];
                
                if (c1 < 3 && c1 != c2 || c1 < c2) {
                    flag = 1;
                    break;
                }
            }
            if (flag != 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
