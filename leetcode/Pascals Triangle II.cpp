class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans; 
        long long el = 1;
        for (int i = 0; i <= rowIndex; i++) {
            ans.push_back(el);
            el = el * (rowIndex - i) / (i + 1);
        }
        return ans;
    }
};
