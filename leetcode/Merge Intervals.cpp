class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int, int>> pairs;
        for (int i = 0; i < (int) intervals.size(); i++) {
            pair<int, int> p;
            p.first = intervals[i][0];
            p.second = intervals[i][1];
            pairs.push_back(p);
        }
        sort(pairs.begin(), pairs.end());   // sort according to first element in the interval
        
        for (pair<int, int> p : pairs) {
            addToAns(p, ans);
        }
        
        return ans;
    }
    
    void addToAns (pair<int, int> p, vector<vector<int>>& ans) {
        int n = (int) ans.size();
        if (ans.empty() || ans[n - 1][1] < p.first) {
            vector<int> new_vect;
            new_vect.push_back(p.first);
            new_vect.push_back(p.second);
            ans.push_back(new_vect);
            return;
        }
        ans[n - 1][1] = max(p.second, ans[n - 1][1]);
    }
};
