class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> res;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        
        for (auto q : queries) {
            res.push_back(-1.0);
            unordered_set<string> visited;
            dfs(q[0], q[1], 1.0, visited);
        }
        
        return res;
    }
    
    void dfs(string curr, string des, double val, unordered_set<string> visited) {
        if (visited.count(curr)) {
            return;
        }
        if (!graph.count(curr)) {
            return;
        }
        if (curr == des) {
            visited.insert(des);
            res[res.size() - 1] = val;
            return;
        }
        if (res[res.size() - 1] != -1.0) {
            return;
        }
        visited.insert(curr);
        
        for (auto p : graph[curr]) {
            dfs(p.first, des, val * p.second, visited);
        }
        
        visited.erase(curr);
    }
    
};
