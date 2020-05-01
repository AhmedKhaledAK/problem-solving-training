class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());
        backtrack(ans, candidates, v, target, 0);
        return ans;
    }
    
    void backtrack (vector<vector<int>>& ans, vector<int>& candidates, 
                    vector<int>& v, int target, int i) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        while (i < (int) candidates.size() && target - candidates[i] >= 0) {
            v.push_back(candidates[i]);
            int currtarget = target - candidates[i];
            backtrack(ans, candidates, v, currtarget, i);
            i++;
            v.pop_back();
        }
    }
    
};
