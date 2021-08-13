class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (string op : logs) {
            if (op == "../" && ans > 0) {
                ans--;
            } else if (op != "./" && op != "../") {
                ans++;
            }
        }
        return ans;
    }
};