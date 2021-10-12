class Solution {
public:
    int maxVowels(string s, int k) {
        int sz = s.size();
        vector<int> ar(sz);
        for (int i = 0; i < sz; i++) {
            int c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ar[i] = 1;
            } else {
                ar[i] = 0;
            }
        }
        vector<int> prefix(sz + 1);
        prefix[0] = 0;
        for (int i = 1; i < sz + 1; i++) {
            prefix[i] = prefix[i - 1] + ar[i - 1];
        }
        int ans, i, j;
        ans = i = 0;
        j = k;
        while (j < sz + 1) {
            ans = max(ans, prefix[j++] - prefix[i++]);
        }
        return ans;
    }
};
