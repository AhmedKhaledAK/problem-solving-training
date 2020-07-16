class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX, profit = 0;
        for (int i = 0; i < (int) prices.size(); i++) {
            if (mn > prices[i]) {
                mn = prices[i];
            } else if (prices[i] - mn > profit) {
                profit = prices[i] - mn;
            }
        }
        return profit;
    }
};
