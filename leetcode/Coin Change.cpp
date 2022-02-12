class Solution {
public:
    int coinChange(vector<int>& denoms, int n) {
        // Write your code here.
        vector<int> numOfCoins(n + 1, INT_MAX);
        numOfCoins[0] = 0;
        int toCompare = 0;
        for (int denom : denoms) {
            for (int amount = 0; amount < numOfCoins.size(); amount++) {
                if (denom <= amount) {
                    if (numOfCoins[amount - denom] == INT_MAX) {
                        toCompare = numOfCoins[amount - denom];
                    } else {
                        toCompare = numOfCoins[amount - denom] + 1;
                    }
                    numOfCoins[amount] = min(toCompare, numOfCoins[amount]);
                }
            }
        }
      return numOfCoins[n] != INT_MAX ? numOfCoins[n] : -1;
    }
};
