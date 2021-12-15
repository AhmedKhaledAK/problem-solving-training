class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (min(n1, n2) * 6 < max(n1, n2)) {
            return -1;
        }
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (sum1 == sum2) {
            return 0;
        }
        
        int count = 0;
        
        if (sum1 < sum2) {
            swap(nums1, nums2);
        }
        int diff = abs(sum1 - sum2);
        map<int, int> mp;
        for (int n : nums1) {
            mp[n - 1]++;
        }
        for (int n : nums2) {
            mp[6 - n]++;
        }
        for (auto p = mp.rbegin(); p != mp.rend(); p++) {
            int n = p->first;
            int t = p->second;
            while (t && diff > 0) {
                diff -=n;
                t--;
                count++;
            }
            if (diff <= 0) {
                return count;
            }
        }
        return -1;
    }
};
