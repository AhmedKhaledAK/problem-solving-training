class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = (int) nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> pos(n, 0);
        vector<int> neg(n, 0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    pos[i] = max(pos[i], neg[j] + 1);
                } else if (nums[i] < nums[j]) {
                    neg[i] = max(neg[i], pos[j] + 1);
                }
            }
        }
        return max(pos[n - 1], neg[n - 1]) + 1;
    }
};
