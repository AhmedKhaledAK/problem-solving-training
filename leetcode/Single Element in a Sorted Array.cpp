class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int exor = 0;
        for (int num : nums) {
            exor ^= num;
        }
        return exor;
    }
};
// time: O(n), space: O(1)
