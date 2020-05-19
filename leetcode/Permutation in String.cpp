class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ns1 = s1.length(), ns2 = s2.length();
        if (ns1 > ns2) {
            return false;
        }
        vector<int> ns1freq(128), ns2freq(128);
        for (int i = 0; i < ns1; i++) {
            ns2freq[s2[i]]++;
            ns1freq[s1[i]]++;
        }
        int k;
        for (int i = ns1; i < ns2; i++) {
            if (compare(ns1freq, ns2freq)) {
                return true;
            }
            ns2freq[s2[i]]++;
            ns2freq[s2[i - ns1]]--;
        }
        if (compare(ns1freq, ns2freq)) {
            return true;
        }
        return false;
    }
    
    bool compare (vector<int> v1, vector<int> v2) {
        for (int i = 0; i < 128; i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};
