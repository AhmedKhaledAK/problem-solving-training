class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }
        res[0] = pre[n - 1] - pre[0] - nums[0] * (n - 1);
        for (int i = 1; i < n; i++) {
            res[i] = (nums[i] * i - pre[i - 1]) + (pre[n - 1] - pre[i]) - nums[i] * (n - 1 - i);
        }
        return res;
    }
};
