class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int ans, sum;
        sum = ans = 0;
        unordered_map<int, int> range;
        for (int i = 0; i < hours.size(); i++) {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0) {
                ans = i + 1;
            } else {
                if (range.find(sum - 1) != range.end()) {
                    int len = i - range[sum - 1];
                    ans = max(ans, len);
                } else if (range.find(sum) == range.end()) {
                    range[sum] = i;
                }
            }
        }
        return ans;
    }
};
