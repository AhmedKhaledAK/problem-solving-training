class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = (int) nums.size();
        vector<vector<int>> ans;
        int sz = 1 << n;
        set<vector<int>> st;
        for (int i = 0; i < sz; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    v.push_back(nums[j]);
                }
            }
            sort(v.begin(), v.end());
            if (st.find(v) == st.end())
                ans.push_back(v);
            st.insert(v);
        }
        return ans;
    }
};
// lazy approach, i was just training on bit manipulation
