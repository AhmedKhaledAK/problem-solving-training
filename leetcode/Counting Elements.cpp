class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> st;
        int ans = 0;
        for (auto&  e : arr)
            st.insert(e);
        for (auto& e : arr) {
            if (st.find(e+1) != st.end()) 
                ans++;
        }
        return ans;
    }
};
