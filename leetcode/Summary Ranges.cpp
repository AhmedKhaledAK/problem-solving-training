class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = (int) nums.size();
        if (n == 0) {
            return {};
        }
        int first, last;
        first = last = nums[0];
        vector<string> ret;
        for (int i = 1; i < n; i++) {
            if ((long long) nums[i] - (long long) nums[i - 1] > 1) {
                last = nums[i - 1];
                if (last != first) {
                    ret.push_back(to_string(first) + "->" + to_string(last));
                } else {
                    ret.push_back(to_string(first));
                }
                first = last = nums[i];
            } else {
                last = nums[i];
            }
        }
        
        if (last != first) {
            ret.push_back(to_string(first) + "->" + to_string(last));
        } else {
            ret.push_back(to_string(first));
        }
        
        return ret;
    }
};
