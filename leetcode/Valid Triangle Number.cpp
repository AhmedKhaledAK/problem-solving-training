class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < sz - 1 && nums[i] != 0; j++) {
                while (k < sz && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};
