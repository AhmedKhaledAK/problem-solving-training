class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if (graph[0].size() == 0) {
            return {};
        }
        vector<vector<int>> paths;
        vector<int> path;
        solve(path, paths, graph, 0);
        return paths;
    }
    
    void solve(vector<int>& path, vector<vector<int>>& paths, vector<vector<int>>& graph, int i) {
        path.push_back(i);
        if (i == graph.size() - 1) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for (int k = 0; k < graph[i].size(); k++) {
            solve(path, paths, graph, graph[i][k]);
        }
        path.pop_back();
    }
};
