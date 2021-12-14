class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        return MCM(nums, 1, n - 1, mem);
    }
    
    int MCM(vector<int>& nums, int left, int right, vector<vector<int>>& mem) {
        if (left >= right) {
            return 0;
        }
        if (mem[left][right] != -1) {
            return mem[left][right];
        }
        int maxCost = INT_MIN;
        for (int k = left; k < right; k++) {
            int totalCost = MCM(nums, left, k, mem) + MCM(nums, k + 1, right, mem) + 
                nums[left - 1] * nums[k] * nums[right];
            maxCost = max(maxCost, totalCost);
            mem[left][right] = maxCost;
        }
        return mem[left][right];
    }
};
