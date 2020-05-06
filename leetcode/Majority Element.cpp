class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = (int) nums.size();
        unordered_map<int, int> freq;
        for (int num : nums) {
            if (++freq[num] > n / 2) {
                return num;
            }
        }
        return 0;   // never reaches it because we assume the element always exists
    }
};
