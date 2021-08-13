class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        int len = (int) nums.size();
        int mn = *min_element(nums.begin(), nums.end());
        return sum - (mn * len);
    }
};