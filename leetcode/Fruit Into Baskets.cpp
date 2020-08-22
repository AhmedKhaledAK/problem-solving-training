class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = (int) tree.size();
        vector<int> blockStarts;
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || tree[i - 1] != tree[i]) {
                blockStarts.push_back(i);
            }
        }
        blockStarts.push_back(tree.size());
        unordered_set<int> types;
        int j, ans, weight;
        j = ans = weight = 0;
        for (int i = 0; i < blockStarts.size() - 1; i++) {
            types.insert(tree[blockStarts[i]]);
            weight += blockStarts[i + 1] - blockStarts[i];
            
            if (types.size() >= 3) {
                i = i - 2;
                types.clear();
                weight = 0;
                continue;
            }
            ans = max(ans, weight);
        }
        return ans;
    }
};
