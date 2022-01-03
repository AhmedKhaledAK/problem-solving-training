class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int lo = 0, hi = tokens.size() - 1;
        int score, ans;
        score = ans = 0;
        while (lo <= hi && (P >= tokens[lo] || score > 0)) {
            while (lo <= hi && P >= tokens[lo]) {
                P -= tokens[lo++];
                score++;
            }
            ans = max(ans, score);
            if (lo <= hi && score > 0) {
                P += tokens[hi--];
                score--;
            }
        }
        return ans;
    }
};
