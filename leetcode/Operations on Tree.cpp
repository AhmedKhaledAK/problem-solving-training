class LockingTree {
    vector<vector<int>> adj;
    unordered_map<int, int> locked;
    unordered_map<int, int> anc;
public:
    LockingTree(vector<int>& parent) {
        adj = vector<vector<int>> (parent.size());
        anc[0] = -1;
        for (int i = 1; i < parent.size(); i++) {
            anc[i] = parent[i];
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked.find(num) != locked.end()) {
            return false;
        }
        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked.find(num) == locked.end()) {
            return false;
        }
        if (locked[num] != user) {
            return false;
        }
        locked.erase(num);
        return true;
    }
    
    bool upgrade(int num, int user) {
        if (locked.find(num) != locked.end()) {
            return false;
        }
        if (dfs(num) && checkAnc(anc[num])) {
            unlockDes(num);
            locked[num] = user;
            return true;
        }
        return false;
    }
    
    bool dfs(int src) {
        for (int i = 0; i < adj[src].size(); i++) {
            int num = adj[src][i];
            if (locked.find(num) != locked.end() || dfs(num)) {
                return true;
            }
        }
        return false;
    }
    
    bool checkAnc(int up) {
        while (up != -1) {
            if (locked.find(up) != locked.end()) {
                return false;
            }
            up = anc[up];
        }
        return true;
    }
    
    void unlockDes(int src) {
        for (int i = 0; i < adj[src].size(); i++) {
            int num = adj[src][i];
            if (locked.find(num) != locked.end()) {
                locked.erase(num);
            }
            unlockDes(num);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
