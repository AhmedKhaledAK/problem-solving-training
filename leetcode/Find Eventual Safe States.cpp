class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> color(N, 0);
        vector<int> ans;
        for (int i = 0; i < N; i++) {
            if (dfs(i, color, graph))
                ans.push_back(i);
        }
        return ans;
    }
    
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
        if (color[node] > 0) { return color[node] == 2; }
        color[node] = 1;
        for (int nei : graph[node]) {
            if (color[node] == 2)
                continue;
            if (color[nei] == 1 || !dfs(nei, color, graph))
                return false;
        }
        color[node] = 2;
        return true;
    }
};
