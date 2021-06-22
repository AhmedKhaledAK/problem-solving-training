class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        vector<int> res;
        for (int n : nums1) {
            st.insert(n);
        }
        for (int n : nums2) {
            if (st.count(n) == 1) {
                res.push_back(n);
                st.erase(n);
            }
        }
        return res;
    }
};