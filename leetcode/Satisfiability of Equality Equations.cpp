class Solution {
    int find(char x, unordered_map<int, int>& parent)
    {
        if (parent[x] != x) parent[x] = find(parent[x], parent);
        return parent[x];
    }
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map<int, int> parent;
        for (auto it : equations)
        {
            parent[it[0]] = it[0];
            parent[it[3]] = it[3];
        }
        for (auto it : equations)
        {
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            if (it[1] == '=') parent[x] = y;
        }
        for (auto it : equations)
        {
            char x = find(it[0], parent);
            char y = find(it[3], parent);
            if (it[1] == '!' && x == y) return false;
        }
        return true;
    }
};
