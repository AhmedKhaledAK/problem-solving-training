class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        vector<int> ans;
        if (np > ns) {
            return ans;
        }
        vector<int> sfreq(128), pfreq(128);
        for (int i = 0; i < np; i++) {
            pfreq[p[i]]++;
            sfreq[s[i]]++;
        }
        int j = 0;
        int k;
        for (int i = np; i < ns; i++) {
            for (k = 0; k < 128; k++) {
                if (sfreq[k] != pfreq[k]) {
                    break;
                }
            }
            if (k == 128) {
                ans.push_back(i - np);
            }
            sfreq[s[i]]++;
            sfreq[s[i - np]]--;
        }
        for (k = 0; k < 128; k++) {
            if (sfreq[k] != pfreq[k]) {
                break;
            }
        }
        if (k == 128) {
            ans.push_back(ns - np);
        }
        return ans;
    }
};
