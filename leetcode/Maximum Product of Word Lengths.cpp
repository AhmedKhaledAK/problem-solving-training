class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = (int) words.size();
        vector<int> bitMaps(sz);
        int ans, s1, s2;
        ans = s1 = s2 = 0;
        for (int i = 0; i < sz; i++) {
            s1 = words[i].size();
            for (int j = 0; j < s1; j++) {
                bitMaps[i] |= (1 << words[i][j] - 'a');
            }
            for (int j = 0; j < i; j++) {
                s2 = words[j].size();
                if ((bitMaps[i] & bitMaps[j]) == 0) ans = max(ans, s1 * s2);
            }
        }
        return ans;
    }
};
