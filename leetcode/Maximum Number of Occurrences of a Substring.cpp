class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size(), res = 0;
        unordered_map<string, int> freq;
        for (int i = 0; i <= n - minSize; i++) {
            for (int j = i + minSize - 1; j < i + maxSize && j < n; j++) {
                int mask, cnt;
                mask = cnt = 0;
                for (int k = i; k <= j; k++) {
                    if ( ((1 << (s[k] - 'a')) & mask) == 0) {
                        cnt++;
                        mask |= (1 << (s[k] - 'a'));
                    }
                }
                if (cnt <= maxLetters) {
                    string ans = "";
                    for (int k = i; k <= j; k++) {
                        ans += s[k];
                    }
                    freq[ans]++;
                }
            }
        }
        for (auto it = freq.begin(); it != freq.end(); it++) {
            res = max(it->second, res);
        }
        return res;
    }
};
