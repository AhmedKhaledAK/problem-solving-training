class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            helper(i, n, result);
        }
        return result;
    }
    
    bool helper(int num, int n, vector<int> &result) {
        if (num > n) return false;
        result.push_back(num);
        for (int i = 0; i <= 9; i++) {
            if(!helper(num*10 + i, n, result)) break;
        }
        return true;
    }
};