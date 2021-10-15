class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> tree(n);
        vector<bool> vis(n);
        for (int i = 0; i < edges.size(); i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        return max(0, 2 * (solve(0, tree, hasApple, vis) - 1));
    }
    
    int solve(int src, vector<vector<int>>& tree, vector<bool>& hasApple, vector<bool>& vis)
    {
        vis[src] = true;
        int time = 0;
        for (const auto& nei : tree[src]) {
            if (!vis[nei]) {
                time += solve(nei, tree, hasApple, vis);
            }
        }
        return (time || hasApple[src]) ? time + 1 : 0;
    }
};
