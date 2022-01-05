class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int res = 0;
        int n = bombs.size();
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            res = max(res, dfs(bombs, i, st));
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& bombs, int i, unordered_set<int>& st) {
        if (st.count(i)) {
            return 0;
        }
        st.insert(i);
        int ret = 1;
        int n = bombs.size();
        for (int j = 0; j < n; j++) {
            if (st.count(j) == 0 &&
                pow((long long) bombs[i][2], 2) >=
                (long long)pow(bombs[i][0] - bombs[j][0], 2) +
                (long long)pow(bombs[i][1] - bombs[j][1], 2)) {
                ret += dfs(bombs, j, st);
            }
        }
        return ret;
    }
};
