class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> graph;
        vector<int> visited(numCourses);
        for (vector<int> v : pre) {
            graph[v[1]].push_back(v[0]);
        }
        return dfs(visited, graph);
    }
    
    bool dfs(vector<int>& visited, unordered_map<int, vector<int>>& graph) {
        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == 0) {
                if (!visit(visited, graph, i)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool visit(vector<int>& visited, unordered_map<int, vector<int>>& graph, int v) {
        visited[v] = 1;
        vector<int> conn = graph[v];
        
        for (int i = 0; i < conn.size(); i++) {
            if (visited[conn[i]] == 0) {
                if (!visit(visited, graph, conn[i])) {
                    return false;
                }
            } else if (visited[conn[i]] == 1) {
                return false;
            }
        }
        visited[v] = 2;
        return true;
    }
};