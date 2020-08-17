class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int npid = pid.size();
        int nppid = ppid.size();
        if (npid == 0 || nppid == 0) {
            return {};
        }
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < npid; i++) {
            mp[ppid[i]].push_back(pid[i]);
        }
        solve(ans, mp, kill);
        return ans;
    }
    
    void solve(vector<int>& ans, unordered_map<int, vector<int>>& mp, int kill) {
        ans.push_back(kill);
        vector<int> procs = mp[kill];
        
        for (int i = 0; i < procs.size(); i++) {
            solve(ans, mp, procs[i]);
        }
    }
};
