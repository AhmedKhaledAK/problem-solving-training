class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp = {1};
        int two, three, five;
        two = three = five = 0;
        for (int i = 0; i < n - 1; i++) {
            int ugly = min({2 * dp[two], 3 * dp[three], 5 * dp[five]});
            dp.push_back(ugly);
            if (ugly == 2 * dp[two]) {
                two++;
            } 
            if (ugly == 3 * dp[three]) {
                three++;
            } 
            if (ugly == 5 * dp[five]) {
                five++;
            }
        }
        return dp.back();
    }
};
