class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) { return 0; }
        int ans = 0;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] < mn) { mn = prices[i]; }
            else if (prices[i] > mn + fee) {
                ans += prices[i] - mn - fee;
                mn = prices[i] - fee;
            }
        }
        return ans;
    }
};
