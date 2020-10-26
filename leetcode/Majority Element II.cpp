class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = (int) nums.size();
        int cnt1, cnt2, first, second;
        cnt1 = cnt2 = 0;
        first = second = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (first == nums[i]) {
                cnt1++;
            } else if (second == nums[i]) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnt1++;
                first = nums[i];
            } else if (cnt2 == 0) {
                cnt2++;
                second = nums[i];
            } else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = cnt2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == first) {
                cnt1++;
            } else if (nums[i] == second) {
                cnt2++;
            }
        }
        
        vector<int> ret;
        
        if (cnt1 > n / 3) {
            ret.push_back(first);
        }
        if (cnt2 > n / 3) {
            ret.push_back(second);
        }
        return ret;
    }
};
