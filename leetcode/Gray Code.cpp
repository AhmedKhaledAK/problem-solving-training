class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        unordered_map<int, bool> visit;
        bt(ans, visit, n, 0);
        return ans;
    }
    
    void bt (vector<int>& ans, unordered_map<int, bool>& visit, 
             int n, int num) {
        if (visit.find(num) != visit.end()) {
            return;
        }
        visit[num] = true;
        ans.push_back(num);
        int shift = 0;
        while (shift < n) {
            int number = num ^ (1 << shift);
            bt(ans, visit, n, number);
            shift++;
        }
    }
};
