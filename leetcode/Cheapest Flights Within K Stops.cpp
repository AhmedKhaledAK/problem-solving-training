class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        vector<vector<pair<int,int>>> adjList(n);
        
        for (vector<int> flight: flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});                
        }
        vector<bool> visited(n);
        int mn = INT_MAX;
        dfs(adjList, src, dst, K, mn, 0, visited);
        return mn == INT_MAX ? -1 : mn;
    }
    
    void dfs(vector<vector<pair<int,int>>>& adjList, int src, int dst, int K, int& mn, int total, vector<bool>& visited) {
        if (K < - 1) {
            return;
        }
        if (src == dst) {
            mn = min(mn, total);
            return;
        }
        visited[src] = true;
        for (int i = 0; i < adjList[src].size(); i++) {
            if (!visited[adjList[src][i].first] && total + adjList[src][i].second <= mn) {
                dfs(adjList, adjList[src][i].first, dst, K - 1, mn,  total + adjList[src][i].second, visited);
            }
        }
        visited[src] = false;
    }
    
};
