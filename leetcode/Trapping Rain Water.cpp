class Solution {
public:
    int trap(vector<int>& height) {
        int n = (int) height.size();
        int ans = 0;
    
        stack<int> st;
        
        for (int j = 0; j < n; j++) {
            int h = height[j];
            while (!st.empty() && h > height[st.top()]) {
                int t = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                ans += (j - st.top() - 1) * (min(h, height[st.top()]) - height[t]);
            }
            st.push(j);
        }
        
        return ans;
    }
};
