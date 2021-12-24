class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxElement = *max_element(candies.begin(), candies.end());
        int n = (int) candies.size();
        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            int candy = candies[i];
            if (candy + extraCandies >= maxElement) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
