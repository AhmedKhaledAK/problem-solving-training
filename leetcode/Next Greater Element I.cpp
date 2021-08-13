class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> st;
        
        for (int i = 0; i < nums2.size(); i++) {
            while(!st.empty() && nums2[i] > st.top()) {
                next[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            if (next.find(nums1[i]) == next.end()) {
                ans.push_back(-1);
            } else {
                ans.push_back(next[nums1[i]]);
            }
        }
        return ans;
    }
};