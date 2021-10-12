class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto conn : connections) {
            graph[conn[0]].push_back({conn[1], 1});
            graph[conn[1]].push_back({conn[0], 0});
        }
        int ans = 0;
        vector<bool> visited(n, false);
        dfs(0, graph, ans, visited);
        return ans;
    }
    
    void dfs(int src , vector<vector<pair<int,int>>> &graph , int &totalWeight , vector<bool> &vis) {
        vis[src] = true;
        for (auto nbr : graph[src]) {
            if (!vis[nbr.first]) {
                totalWeight += nbr.second;
                dfs(nbr.first, graph, totalWeight, vis);
            }
        }
    }
};
