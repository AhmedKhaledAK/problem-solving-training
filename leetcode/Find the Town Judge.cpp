class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int sz = (int) trust.size();
        vector<int> trusts(N), trusted(N);
        for (int i = 0; i < sz; i++) {
            trusts[trust[i][0] - 1]++;
            trusted[trust[i][1] - 1]++;
        }
        for (int i = 0; i < N; i++) {
            if (trusts[i] == 0 && trusted[i] == N - 1) {
                return i + 1;
            }
        }
        return -1;
    }
};
