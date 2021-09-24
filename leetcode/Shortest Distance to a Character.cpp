class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int N = (int) s.size();
        vector<int> res(N);
        int prev = INT_MIN / 2;
        for (int i = 0; i < N; i++)
        {
            if (s[i] == c) prev = i;
            res[i] = i - prev;
        }
        prev = INT_MAX / 2;
        for (int i = N - 1; i >= 0; i--)
        {
            if (s[i] == c) prev = i;
            res[i] = min(res[i], prev - i);
        }
        return res;
    }
};
