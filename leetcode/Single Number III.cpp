class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int exor = 0;
        for (int num : nums) {
            exor ^= num;
        }
        int diffBit = 0;
        while ((exor & (1 << diffBit)) == 0) {
            diffBit++;
        }
        int ans1 = 0;
        for (int num : nums) {
            if ((num & (1 << diffBit)) != 0) {
                ans1 ^= num;
            }
        }
        int ans2 = exor ^ ans1;
        return vector<int> ({ans1, ans2});
    }
};
