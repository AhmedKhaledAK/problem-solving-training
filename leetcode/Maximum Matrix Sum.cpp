class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool even = true;
        int mn = INT_MAX;
        long long sum = 0;
        for (auto row : matrix) {
            for (int num : row) {
                if (num < 0) {
                    even = !even;
                    num = -num;
                }
                mn = min(mn, num);
                sum += num;
            }
        }
        return even ? sum : sum - 2 * mn;
    }
};
