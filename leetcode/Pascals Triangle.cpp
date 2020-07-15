class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int j = 1;
        for (int i = 0; i < numRows; i++) {
            vector<int> v;
            for (int k = 0; k < j; k++) {
                if (k == 0 || k == j - 1) {
                    v.push_back(1);
                    continue;
                }
                int el = ans[i - 1][k] + ans[i - 1][k - 1];
                v.push_back(el);
            }
            j++;
            ans.push_back(v);
        }
        return ans;
    }
};
