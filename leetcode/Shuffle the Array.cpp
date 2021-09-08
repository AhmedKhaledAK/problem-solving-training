class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int firstHalf = 0; firstHalf < n; firstHalf++)
        {
            res.push_back(nums[firstHalf]);
            res.push_back(nums[firstHalf + n]);
        }
        return res;
    }
};
