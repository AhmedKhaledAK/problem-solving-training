class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smp;
        unordered_map<char, char> tmp;
        for (int i = 0; i < s.size(); i++) {
            if (smp.count(s[i]) == 0) {
                if (tmp.count(t[i]) != 0) {
                    return false;
                }
                smp[s[i]] = t[i];
                tmp[t[i]] = s[i];
            } else {
                if (smp[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
