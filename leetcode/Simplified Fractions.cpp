class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        string str;
        vector<string> frac;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i / j < 1 && __gcd(i, j) == 1) {
                    str = to_string(i);
                    str += '/';
                    str += to_string(j);
                    frac.push_back(str);
                }
            }
        }
        return frac;
    }
};
