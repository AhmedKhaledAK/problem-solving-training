class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        vector<vector<int>> res;
        int sum = 0;
        bt(0, n, k, sum, v, res);
        return res;
    }
    
    void bt(int num, int & n, int & k, int & sum, 
            vector<int> & v, vector<vector<int>> & res) {
        if (v.size() == k && sum == n) {
            res.push_back(v);
            return;
        }
        for (int i = num + 1; i <= 9; i++) {
            v.push_back(i);
            sum += i;
            bt(i, n, k, sum, v, res);
            sum -= i;
            v.pop_back();
        }
    }
    
};
