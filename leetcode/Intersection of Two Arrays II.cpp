class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> result;
        for (int n : nums1) {
            freq[n]++;
        }
        for (int n : nums2) {
            if (freq.find(n) != freq.end()) {
                if (freq[n] != 0) {
                    result.push_back(n);
                    freq[n]--;
                }
            }
        }
        return result;
    }
};