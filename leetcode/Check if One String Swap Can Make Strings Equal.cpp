class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int count = 0;
        char cs11, cs12, cs21, cs22;
        cs11 = cs12 = cs21 = cs22 = ' ';
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (count == 2) {
                    return false;
                }
                if (count == 0) {
                    cs11 = s1[i];
                    cs21 = s2[i];
                    count++;
                } else {
                    cs12 = s1[i];
                    cs22 = s2[i];
                    count++;
                }
            }
        }
        return cs11 == cs22 && cs12 == cs21;
    }
};
